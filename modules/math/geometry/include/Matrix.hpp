#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <type_traits>

/**
 * Generic Matrix Template Class
 * 
 * Template parameters:
 * - T: Element type (float, double, int, etc.)
 * - Default uses dynamic sizing with std::vector
 * 
 * Features:
 * - Dynamic n×m matrix dimensions
 * - Gaussian elimination with partial pivoting
 * - Moore-Penrose pseudoinverse for rectangular matrices
 * - LU decomposition with partial pivoting
 * - Comprehensive matrix operations
 * - Numerical stability enhancements
 */
namespace math {

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data_;
    size_t rows_;
    size_t cols_;
    
    // Numerical tolerance for floating-point comparisons
    static constexpr T DEFAULT_EPSILON = static_cast<T>(1e-10);
    T epsilon_;
    
public:
    // ==================== CONSTRUCTORS ====================
    
    /**
     * Default constructor - creates empty matrix
     */
    Matrix() : rows_(0), cols_(0), epsilon_(DEFAULT_EPSILON) {}
    
    /**
     * Dimension constructor - creates zero-initialized matrix
     */
    Matrix(size_t rows, size_t cols) 
        : rows_(rows), cols_(cols), epsilon_(DEFAULT_EPSILON) {
        if (rows == 0 || cols == 0) {
            throw std::invalid_argument("Matrix dimensions must be positive");
        }
        data_.resize(rows, std::vector<T>(cols, T{}));
    }
    
    /**
     * Initializer list constructor for small matrices
     */
    Matrix(std::initializer_list<std::initializer_list<T>> init) 
        : epsilon_(DEFAULT_EPSILON) {
        if (init.size() == 0) {
            rows_ = cols_ = 0;
            return;
        }
        
        rows_ = init.size();
        cols_ = init.begin()->size();
        
        if (cols_ == 0) {
            throw std::invalid_argument("Matrix cannot have zero columns");
        }
        
        data_.reserve(rows_);
        for (const auto& row : init) {
            if (row.size() != cols_) {
                throw std::invalid_argument("All rows must have the same number of columns");
            }
            data_.emplace_back(row);
        }
    }
    
    /**
     * Copy constructor
     */
    Matrix(const Matrix& other) 
        : data_(other.data_), rows_(other.rows_), cols_(other.cols_), epsilon_(other.epsilon_) {}
    
    /**
     * Move constructor
     */
    Matrix(Matrix&& other) noexcept 
        : data_(std::move(other.data_)), rows_(other.rows_), cols_(other.cols_), epsilon_(other.epsilon_) {
        other.rows_ = other.cols_ = 0;
    }
    
    // ==================== ASSIGNMENT OPERATORS ====================
    
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            data_ = other.data_;
            rows_ = other.rows_;
            cols_ = other.cols_;
            epsilon_ = other.epsilon_;
        }
        return *this;
    }
    
    Matrix& operator=(Matrix&& other) noexcept {
        if (this != &other) {
            data_ = std::move(other.data_);
            rows_ = other.rows_;
            cols_ = other.cols_;
            epsilon_ = other.epsilon_;
            other.rows_ = other.cols_ = 0;
        }
        return *this;
    }
    
    // ==================== ACCESSORS ====================
    
    size_t rows() const { return rows_; }
    size_t cols() const { return cols_; }
    T getEpsilon() const { return epsilon_; }
    void setEpsilon(T eps) { epsilon_ = eps; }
    
    /**
     * Element access with bounds checking
     */
    T& operator()(size_t row, size_t col) {
        if (row >= rows_ || col >= cols_) {
            throw std::out_of_range("Matrix index out of bounds");
        }
        return data_[row][col];
    }
    
    const T& operator()(size_t row, size_t col) const {
        if (row >= rows_ || col >= cols_) {
            throw std::out_of_range("Matrix index out of bounds");
        }
        return data_[row][col];
    }
    
    /**
     * Row access
     */
    std::vector<T>& operator[](size_t row) {
        if (row >= rows_) {
            throw std::out_of_range("Row index out of bounds");
        }
        return data_[row];
    }
    
    const std::vector<T>& operator[](size_t row) const {
        if (row >= rows_) {
            throw std::out_of_range("Row index out of bounds");
        }
        return data_[row];
    }
    
    // ==================== UTILITY FUNCTIONS ====================
    
    
    /**
     * Create identity matrix
     */
    static Matrix identity(size_t n) {
        Matrix result(n, n);
        for (size_t i = 0; i < n; ++i) {
            result(i, i) = T{1};
        }
        return result;
    }

/**
 * Same as above, but accepts a vector of a different (convertible) value type U.
 * Values are static_cast to T.
 */
template <class U>
static Matrix FromVector(const std::vector<U>& v, bool asColumn = true) {
    const size_t n = v.size();
    if (n == 0) {
        return Matrix(); // empty by convention
    }
    Matrix M(asColumn ? n : 1, asColumn ? 1 : n);
    if (asColumn) {
        for (size_t i = 0; i < n; ++i) M(i, 0) = static_cast<T>(v[i]);
    } else {
        for (size_t j = 0; j < n; ++j) M(0, j) = static_cast<T>(v[j]);
    }
    return M;
}
    /**
 * Create a matrix with 'diagonal' placed on the k-th diagonal (minimal shape).
 * If diagonal is empty and k == 0, returns an empty matrix (0×0).
 * Otherwise, shape is:
 *   rows = diagonal.size() + max(0, -k)
 *   cols = diagonal.size() + max(0,  k)
 * All non-diagonal entries are T{}.
 */
static Matrix DiagonalMatrix(const std::vector<T>& diagonal, int k = 0) {
    const size_t n = diagonal.size();
    const size_t minRows = n + (k < 0 ? static_cast<size_t>(-k) : size_t{0});
    const size_t minCols = n + (k > 0 ? static_cast<size_t>( k) : size_t{0});

    // Respect class invariant: constructor disallows 0×0, so handle explicitly
    if (minRows == 0 || minCols == 0) {
        return Matrix(); // empty
    }

    Matrix M(minRows, minCols); // zero-initialized
    size_t i = (k < 0) ? static_cast<size_t>(-k) : size_t{0};
    size_t j = (k > 0) ? static_cast<size_t>( k) : size_t{0};

    for (size_t t = 0; t < n && i < minRows && j < minCols; ++t, ++i, ++j) {
        M(i, j) = diagonal[t];
    }
    return M;
}
/**
 * Get a single element (i, j) with bounds checking.
 * Returns a const reference; overload returns non-const reference.
 */
const T& GetElement(size_t i, size_t j) const {
    if (i >= rows_ || j >= cols_) {
        throw std::out_of_range("GetElement: index out of range");
    }
    return (*this)(i, j);
}
T& GetElement(size_t i, size_t j) {
    if (i >= rows_ || j >= cols_) {
        throw std::out_of_range("GetElement: index out of range");
    }
    return (*this)(i, j);
}
    /**
     * Create zero matrix
     */
    static Matrix zeros(size_t rows, size_t cols) {
        return Matrix(rows, cols);
    }
    
    /**
     * Create ones matrix
     */
    static Matrix ones(size_t rows, size_t cols) {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(i, j) = T{1};
            }
        }
        return result;
    }
    
    /**
     * Check if matrix is square
     */
    bool isSquare() const {
        return rows_ == cols_;
    }
    
    /**
     * Check if value is effectively zero (within epsilon)
     */
    bool isZero(T value) const {
        if constexpr (std::is_floating_point_v<T>) {
            return std::abs(value) < epsilon_;
        } else {
            return value == T{0};
        }
    }
    
    /**
     * Check if two values are approximately equal
     */
    bool isEqual(T a, T b) const {
        if constexpr (std::is_floating_point_v<T>) {
            return std::abs(a - b) < epsilon_;
        } else {
            return a == b;
        }
    }
    
    // ==================== BASIC OPERATIONS ====================
    
    /**
     * Matrix addition
     */
    Matrix operator+(const Matrix& other) const {
        if (rows_ != other.rows_ || cols_ != other.cols_) {
            throw std::invalid_argument("Matrix dimensions must match for addition");
        }
        
        Matrix result(rows_, cols_);
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t j = 0; j < cols_; ++j) {
                result(i, j) = data_[i][j] + other(i, j);
            }
        }
        return result;
    }
    
    /**
     * Matrix subtraction
     */
    Matrix operator-(const Matrix& other) const {
        if (rows_ != other.rows_ || cols_ != other.cols_) {
            throw std::invalid_argument("Matrix dimensions must match for subtraction");
        }
        
        Matrix result(rows_, cols_);
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t j = 0; j < cols_; ++j) {
                result(i, j) = data_[i][j] - other(i, j);
            }
        }
        return result;
    }
    
    /**
     * Scalar multiplication
     */
    Matrix operator*(T scalar) const {
        Matrix result(rows_, cols_);
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t j = 0; j < cols_; ++j) {
                result(i, j) = data_[i][j] * scalar;
            }
        }
        return result;
    }
    
    /**
     * Matrix multiplication
     * Time complexity: O(n³)
     */
    Matrix operator*(const Matrix& other) const {
        if (cols_ != other.rows_) {
            throw std::invalid_argument("Matrix dimensions incompatible for multiplication");
        }
        
        Matrix result(rows_, other.cols_);
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t j = 0; j < other.cols_; ++j) {
                T sum = T{0};
                for (size_t k = 0; k < cols_; ++k) {
                    sum += data_[i][k] * other(k, j);
                }
                result(i, j) = sum;
            }
        }
        return result;
    }
    
    /**
     * Matrix transpose
     * Time complexity: O(n²)
     */
    Matrix transpose() const {
        Matrix result(cols_, rows_);
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t j = 0; j < cols_; ++j) {
                result(j, i) = data_[i][j];
            }
        }
        return result;
    }
    
    // ==================== ADVANCED OPERATIONS ====================
    
    /**
     * Calculate determinant using LU decomposition
     * Only valid for square matrices
     * Time complexity: O(n³)
     */
    T determinant() const {
        if (!isSquare()) {
            throw std::invalid_argument("Determinant only defined for square matrices");
        }
        
        if (rows_ == 0) return T{1};
        if (rows_ == 1) return data_[0][0];
        if (rows_ == 2) {
            return data_[0][0] * data_[1][1] - data_[0][1] * data_[1][0];
        }
        
        // Use LU decomposition for larger matrices
        auto [L, U, P, sign] = luDecomposition();
        
        // det(A) = det(P) * det(L) * det(U) = sign * 1 * product(diagonal(U))
        T det = static_cast<T>(sign);
        for (size_t i = 0; i < rows_; ++i) {
            det *= U(i, i);
        }
        
        return det;
    }
    
    /**
     * LU Decomposition with partial pivoting
     * Returns: (L, U, P, sign) where A = P*L*U
     * - L: Lower triangular matrix with ones on diagonal
     * - U: Upper triangular matrix
     * - P: Permutation matrix
     * - sign: Sign of permutation (±1)
     */
    std::tuple<Matrix, Matrix, Matrix, int> luDecomposition() const {
        if (!isSquare()) {
            throw std::invalid_argument("LU decomposition requires square matrix");
        }
        
        size_t n = rows_;
        Matrix L = Matrix::identity(n);
        Matrix U = *this;  // Copy of original matrix
        Matrix P = Matrix::identity(n);
        int sign = 1;
        
        for (size_t k = 0; k < n - 1; ++k) {
            // Find pivot (partial pivoting)
            size_t pivotRow = k;
            T maxVal = std::abs(U(k, k));
            
            for (size_t i = k + 1; i < n; ++i) {
                if (std::abs(U(i, k)) > maxVal) {
                    maxVal = std::abs(U(i, k));
                    pivotRow = i;
                }
            }
            
            // Swap rows if needed
            if (pivotRow != k) {
                U.swapRows(k, pivotRow);
                P.swapRows(k, pivotRow);
                if (k > 0) {
                    L.swapRowsPartial(k, pivotRow, k);  // Only swap the computed part of L
                }
                sign *= -1;
            }
            
            // Check for singular matrix
            if (isZero(U(k, k))) {
                throw std::runtime_error("Matrix is singular - LU decomposition failed");
            }
            
            // Gaussian elimination
            for (size_t i = k + 1; i < n; ++i) {
                T factor = U(i, k) / U(k, k);
                L(i, k) = factor;
                
                for (size_t j = k; j < n; ++j) {
                    U(i, j) -= factor * U(k, j);
                }
            }
        }
        
        return std::make_tuple(L, U, P, sign);
    }
    
    /**
     * Matrix inverse using Gaussian elimination with partial pivoting
     * Only for square matrices
     * Time complexity: O(n³)
     */
    Matrix inverse() const {
        if (!isSquare()) {
            throw std::invalid_argument("Matrix inverse only defined for square matrices");
        }
        
        size_t n = rows_;
        if (n == 0) {
            throw std::invalid_argument("Cannot invert empty matrix");
        }
        
        // Create augmented matrix [A|I]
        Matrix augmented(n, 2 * n);
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                augmented(i, j) = data_[i][j];
                augmented(i, j + n) = (i == j) ? T{1} : T{0};
            }
        }
        
        // Forward elimination with partial pivoting
        for (size_t k = 0; k < n; ++k) {
            // Find pivot
            size_t pivotRow = k;
            T maxVal = std::abs(augmented(k, k));
            
            for (size_t i = k + 1; i < n; ++i) {
                if (std::abs(augmented(i, k)) > maxVal) {
                    maxVal = std::abs(augmented(i, k));
                    pivotRow = i;
                }
            }
            
            // Check for singular matrix
            if (isZero(maxVal)) {
                throw std::runtime_error("Matrix is singular (non-invertible)");
            }
            
            // Swap rows if needed
            if (pivotRow != k) {
                augmented.swapRows(k, pivotRow);
            }
            
            // Scale pivot row
            T pivot = augmented(k, k);
            for (size_t j = 0; j < 2 * n; ++j) {
                augmented(k, j) /= pivot;
            }
            
            // Eliminate column
            for (size_t i = 0; i < n; ++i) {
                if (i != k) {
                    T factor = augmented(i, k);
                    for (size_t j = 0; j < 2 * n; ++j) {
                        augmented(i, j) -= factor * augmented(k, j);
                    }
                }
            }
        }
        
        // Extract inverse matrix from right half of augmented matrix
        Matrix result(n, n);
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                result(i, j) = augmented(i, j + n);
            }
        }
        
        return result;
    }
    
    /**
     * Moore-Penrose pseudoinverse for any matrix
     * 
     * Mathematical approach:
     * For matrix A (m×n):
     * 1. If m >= n and A^T*A is invertible: A+ = (A^T*A)^(-1)*A^T
     * 2. If m < n and A*A^T is invertible: A+ = A^T*(A*A^T)^(-1)
     * 3. Otherwise, use SVD (simplified approach using normal equations)
     * 
     * Time complexity: O(n³)
     */
    Matrix pseudoinverse() const {
        if (rows_ == 0 || cols_ == 0) {
            throw std::invalid_argument("Cannot compute pseudoinverse of empty matrix");
        }
        
        Matrix At = transpose();
        
        try {
            if (rows_ >= cols_) {
                // Method 1: A+ = (A^T*A)^(-1)*A^T (left pseudoinverse)
                Matrix AtA = At * (*this);
                Matrix AtA_inv = AtA.inverse();
                return AtA_inv * At;
            } else {
                // Method 2: A+ = A^T*(A*A^T)^(-1) (right pseudoinverse)
                Matrix AAt = (*this) * At;
                Matrix AAt_inv = AAt.inverse();
                return At * AAt_inv;
            }
        }
        catch (const std::runtime_error&) {
            // Both methods failed - matrix is rank deficient
            // Fallback: use regularized least squares approach
            Matrix AtA = At * (*this);
            
            // Add regularization to diagonal (Tikhonov regularization)
            T regularization = epsilon_ * 1000;  // Small regularization parameter
            for (size_t i = 0; i < AtA.rows(); ++i) {
                AtA(i, i) += regularization;
            }
            
            try {
                Matrix AtA_reg_inv = AtA.inverse();
                return AtA_reg_inv * At;
            }
            catch (const std::runtime_error&) {
                // Complete failure - return zero matrix
                std::cerr << "Warning: Matrix appears to be severely rank-deficient. "
                         << "Returning zero matrix. Consider using SVD for accurate pseudoinverse.\n";
                return Matrix::zeros(cols_, rows_);
            }
        }
    }
    
    /**
     * Calculate matrix rank using Gaussian elimination
     * Time complexity: O(min(m,n)³)
     */
    size_t rank() const {
        if (rows_ == 0 || cols_ == 0) return 0;
        
        Matrix temp = *this;  // Copy for row operations
        size_t rank = 0;
        
        size_t minDim = std::min(rows_, cols_);
        
        for (size_t col = 0, row = 0; col < cols_ && row < rows_; ++col) {
            // Find pivot
            size_t pivotRow = row;
            T maxVal = std::abs(temp(row, col));
            
            for (size_t i = row + 1; i < rows_; ++i) {
                if (std::abs(temp(i, col)) > maxVal) {
                    maxVal = std::abs(temp(i, col));
                    pivotRow = i;
                }
            }
            
            // If column is effectively zero, skip it
            if (isZero(maxVal)) {
                continue;
            }
            
            // Swap rows if needed
            if (pivotRow != row) {
                temp.swapRows(row, pivotRow);
            }
            
            // Eliminate below pivot
            for (size_t i = row + 1; i < rows_; ++i) {
                if (!isZero(temp(i, col))) {
                    T factor = temp(i, col) / temp(row, col);
                    for (size_t j = col; j < cols_; ++j) {
                        temp(i, j) -= factor * temp(row, j);
                    }
                }
            }
            
            ++rank;
            ++row;
        }
        
        return rank;
    }
    
    // ==================== HELPER FUNCTIONS ====================
    
    /**
     * Swap two rows
     */
    void swapRows(size_t row1, size_t row2) {
        if (row1 >= rows_ || row2 >= rows_) {
            throw std::out_of_range("Row index out of bounds");
        }
        if (row1 != row2) {
            std::swap(data_[row1], data_[row2]);
        }
    }
    
    /**
     * Swap partial rows (used in LU decomposition)
     */
    void swapRowsPartial(size_t row1, size_t row2, size_t startCol) {
        if (row1 >= rows_ || row2 >= rows_) {
            throw std::out_of_range("Row index out of bounds");
        }
        if (startCol >= cols_) {
            throw std::out_of_range("Column index out of bounds");
        }
        
        if (row1 != row2) {
            for (size_t j = startCol; j < cols_; ++j) {
                std::swap(data_[row1][j], data_[row2][j]);
            }
        }
    }
    
    /**
     * Check if matrices are approximately equal
     */
    bool isApproximatelyEqual(const Matrix& other, T tolerance = DEFAULT_EPSILON) const {
        if (rows_ != other.rows_ || cols_ != other.cols_) {
            return false;
        }
        
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t j = 0; j < cols_; ++j) {
                if constexpr (std::is_floating_point_v<T>) {
                    if (std::abs(data_[i][j] - other(i, j)) > tolerance) {
                        return false;
                    }
                } else {
                    if (data_[i][j] != other(i, j)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    /**
     * Calculate Frobenius norm
     */
    T frobeniusNorm() const {
        T sum = T{0};
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t j = 0; j < cols_; ++j) {
                sum += data_[i][j] * data_[i][j];
            }
        }
        if constexpr (std::is_floating_point_v<T>) {
            return std::sqrt(sum);
        } else {
            return sum;  // For integer types, return squared norm
        }
    }
    
    /**
     * Print matrix in readable format
     */
    void print(int width = 10, int precision = 6) const {
        std::cout << std::fixed << std::setprecision(precision);
        for (size_t i = 0; i < rows_; ++i) {
            std::cout << "| ";
            for (size_t j = 0; j < cols_; ++j) {
                std::cout << std::setw(width) << data_[i][j] << " ";
            }
            std::cout << "|\n";
        }
        std::cout << std::endl;
    }
    
    /**
     * Get matrix dimensions as string
     */
    std::string dimensionsString() const {
        return std::to_string(rows_) + "×" + std::to_string(cols_);
    }
};






}
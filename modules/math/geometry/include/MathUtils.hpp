#include "Matrix.hpp"

namespace math{

template<typename T>
Matrix<T> Identity(size_t n) {
    Matrix<T> result(n, n);
    for (size_t i = 0; i < n; ++i) {
        result(i, i) = T{1};
    }
    return result;
}

template<typename T>
Matrix<T> Zeros(size_t rows, size_t cols) {
    return Matrix<T>(rows, cols); 
}

// Free function for matrix inverse (for square matrices)
template<typename T>
Matrix<T> Inv(const Matrix<T>& mat) {
    return mat.inverse();
}
// Free function for Moore-Penrose pseudoinverse (for any-size matrices)
template<typename T>
Matrix<T> Pinv(const Matrix<T>& mat) {
    return mat.pseudoinverse();
}

}
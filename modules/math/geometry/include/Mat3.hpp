
#pragma once

#include <iostream>
#include <cmath>
#include <Vector3.hpp>

namespace math {

// Forward declaration for Vector3 class
class Vector3;

class Mat3 {
public:
    // Matrix elements stored as individual members
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;

    // Constructors
    Mat3() : 
        m00(0.0f), m01(0.0f), m02(0.0f),
        m10(0.0f), m11(0.0f), m12(0.0f),
        m20(0.0f), m21(0.0f), m22(0.0f) {}

    Mat3(const Mat3& other) :
        m00(other.m00), m01(other.m01), m02(other.m02),
        m10(other.m10), m11(other.m11), m12(other.m12),
        m20(other.m20), m21(other.m21), m22(other.m22) {}

    Mat3(float _m00, float _m01, float _m02,
                      float _m10, float _m11, float _m12,
                      float _m20, float _m21, float _m22) :
        m00(_m00), m01(_m01), m02(_m02),
        m10(_m10), m11(_m11), m12(_m12),
        m20(_m20), m21(_m21), m22(_m22) {}
    Mat3(const Vector3& col0, const Vector3& col1, const Vector3& col2, bool asColumns = true);
    explicit Mat3(const Vector3& diagonal);  // Diagonal matrix from vector

    // Static factory methods for Vector3 integration
    static Mat3 FromColumns(const Vector3& col0, const Vector3& col1, const Vector3& col2);
    static Mat3 FromRows(const Vector3& row0, const Vector3& row1, const Vector3& row2);
    static Mat3 CrossProductMatrix(const Vector3& vec);        // Skew-symmetric matrix for cross product
    static Mat3 OuterProduct(const Vector3& u, const Vector3& v);  // u ⊗ v
    static Mat3 Diagonal(const Vector3& diagonal);             // Diagonal matrix
    static Mat3 LookAt(const Vector3& eye, const Vector3& target, const Vector3& up);  // Look-at matrix
    static Mat3 FromAxisAngle(const Vector3& axis, float angleRad);  // Rotation from axis-angle
    
    // Row and column operations with Vector3
    Mat3& swapRows(int row1, int row2);
    Mat3& swapColumns(int col1, int col2);
    Mat3 withRow(int row, const Vector3& newRow) const;
    Mat3 withColumn(int col, const Vector3& newCol) const;

    // Create zero matrix
    static Mat3 Scale(float sx, float sy, float sz = 1.0f);   // Create scaling matrix
    static Mat3 RotationX(float angleRad);                    // Create rotation matrix around X-axis
    static Mat3 RotationY(float angleRad);                    // Create rotation matrix around Y-axis
    static Mat3 RotationZ(float angleRad);                    // Create rotation matrix around Z-axis
    static Mat3 Translation(float tx, float ty);              // Create 2D translation matrix
    // Vector3 extraction methods (alternatives to existing getRow/getColumn)
    Vector3 row(int index) const;
    Vector3 column(int index) const;
    Vector3 diagonal() const;                                  // Extract diagonal as Vector3
    // Advanced Vector3 operations
    Vector3 transformPoint(const Vector3& point) const;        // Transform point (homogeneous w=1)
    Vector3 transformVector(const Vector3& vector) const;      // Transform vector (homogeneous w=0)
    Vector3 transformNormal(const Vector3& normal) const;      // Transform normal (using transpose inverse)
    // Friend declarations for Vector3 operators
    friend Vector3 operator*(const Vector3& vec, const Mat3& mat);  // Row vector multiplication
    // Subscript operators for Vector3 access
    Vector3 operator[](int row) const;                         // Get row as Vector3
    void setRowVector(int row, const Vector3& vec);           // Set row from Vector3
    void setColumnVector(int col, const Vector3& vec);        // Set column from Vector3
    // Destructor
    ~Mat3() = default;

    // Assignment operators
    Mat3& operator=(const Mat3& other);
    Mat3& operator+=(const Mat3& other);
    Mat3& operator-=(const Mat3& other);
    Mat3& operator*=(const Mat3& other);
    Mat3& operator*=(float scalar);
    Mat3& operator/=(float scalar);

    // Arithmetic operators
    Mat3 operator+(const Mat3& other) const;
    Mat3 operator-(const Mat3& other) const;
    Mat3 operator*(const Mat3& other) const;
    Mat3 operator*(float scalar) const;
    Mat3 operator/(float scalar) const;
    Mat3 operator-() const;                                    // Unary minus

    // Vector operations
    Vector3 operator*(const Vector3& vec) const;               // Matrix * Vector
    
    // Comparison operators
    bool operator==(const Mat3& other) const;
    bool operator!=(const Mat3& other) const;

    // Element access
    float& operator()(int row, int col);                       // Mutable access
    const float& operator()(int row, int col) const;          // Const access
    
    // Individual element getters
    inline float getM00() const { return m00; }
    inline float getM01() const { return m01; }
    inline float getM02() const { return m02; }
    inline float getM10() const { return m10; }
    inline float getM11() const { return m11; }
    inline float getM12() const { return m12; }
    inline float getM20() const { return m20; }
    inline float getM21() const { return m21; }
    inline float getM22() const { return m22; }

    // Individual element setters
    inline void setM00(float value) { m00 = value; }
    inline void setM01(float value) { m01 = value; }
    inline void setM02(float value) { m02 = value; }
    inline void setM10(float value) { m10 = value; }
    inline void setM11(float value) { m11 = value; }
    inline void setM12(float value) { m12 = value; }
    inline void setM20(float value) { m20 = value; }
    inline void setM21(float value) { m21 = value; }
    inline void setM22(float value) { m22 = value; }

    // Row and column operations
    Vector3 getRow(int row) const;
    Vector3 getColumn(int col) const;
    void setRow(int row, const Vector3& values);
    void setColumn(int col, const Vector3& values);
    void setRow(int row, float x, float y, float z);
    void setColumn(int col, float x, float y, float z);

    // Matrix operations
    Mat3 transpose() const;
    float determinant() const;
    Mat3 inverse() const;
    Mat3 adjugate() const;                                     // Adjugate (classical adjoint) matrix
    float trace() const;                                       // Sum of diagonal elements
    
    // Utility methods
    void print() const;
    void print(const std::string& name) const;
    bool isIdentity(float tolerance = 1e-6f) const;
    bool isZero(float tolerance = 1e-6f) const;
    bool isSymmetric(float tolerance = 1e-6f) const;
    bool isOrthogonal(float tolerance = 1e-6f) const;
    bool isDiagonal(float tolerance = 1e-6f) const;
    float frobeniusNorm() const;                               // Frobenius norm of the matrix
    
    // Modification methods
    void makeIdentity();
    void makeZero();
    void transposeInPlace();
    bool invertInPlace();                                      // Returns false if matrix is not invertible
    void scale(float scalar);
    
    // Interpolation
    static Mat3 lerp(const Mat3& a, const Mat3& b, float t);
    // Constants
    static const Mat3 IDENTITY;
    static const Mat3 ZERO;

private:
    // Helper methods
    float minor(int row, int col) const;                       // Calculate minor for determinant calculation
    bool isEqual(float a, float b, float tolerance) const;     // Floating point comparison helper
};


// Static factory methods
inline static Mat3 Identity3() {
    return Mat3(1.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 1.0f);
}

inline static Mat3 Zero3() {
    return Mat3();
}

} // namespace math

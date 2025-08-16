#include "Mat3.hpp"

namespace math{
// Non-member operators
Mat3 operator*(float scalar, const Mat3& matrix);
std::ostream& operator<<(std::ostream& os, const Mat3& matrix);

// Inline implementations for simple methods
Mat3::Mat3(const Vector3& vec0, const Vector3& vec1, const Vector3& vec2, bool asColumns) {
    if (asColumns) {
        // Treat vectors as columns
        m00 = vec0.GetX(); m01 = vec1.GetX(); m02 = vec2.GetX();
        m10 = vec0.GetY(); m11 = vec1.GetY(); m12 = vec2.GetY();
        m20 = vec0.GetZ(); m21 = vec1.GetZ(); m22 = vec2.GetZ();
    } else {
        // Treat vectors as rows
        m00 = vec0.GetX(); m01 = vec0.GetY(); m02 = vec0.GetZ();
        m10 = vec1.GetX(); m11 = vec1.GetY(); m12 = vec1.GetZ();
        m20 = vec2.GetX(); m21 = vec2.GetY(); m22 = vec2.GetZ();
    }
}

// Static factory methods
Mat3 Mat3::FromColumns(const Vector3& col0, const Vector3& col1, const Vector3& col2) {
    return Mat3(col0, col1, col2, true);
}

Mat3 Mat3::FromRows(const Vector3& row0, const Vector3& row1, const Vector3& row2) {
    return Mat3(row0, row1, row2, false);
}

Mat3 Mat3::CrossProductMatrix(const Vector3& vec) {
    // Creates skew-symmetric matrix such that CrossProductMatrix(a) * b = a.Cross(b)
    return Mat3(0.0f,        -vec.GetZ(),  vec.GetY(),
                vec.GetZ(),   0.0f,        -vec.GetX(),
               -vec.GetY(),   vec.GetX(),   0.0f);
}

Mat3 Mat3::OuterProduct(const Vector3& u, const Vector3& v) {
    // Outer product u ⊗ v = u * v^T
    return Mat3(u.GetX() * v.GetX(), u.GetX() * v.GetY(), u.GetX() * v.GetZ(),
                u.GetY() * v.GetX(), u.GetY() * v.GetY(), u.GetY() * v.GetZ(),
                u.GetZ() * v.GetX(), u.GetZ() * v.GetY(), u.GetZ() * v.GetZ());
}

Mat3 Mat3::Diagonal(const Vector3& diagonal) {
    return Mat3(diagonal);
}

// Diagonal constructor from Vector3
Mat3::Mat3(const Vector3& diagonal) :
    m00(diagonal.GetX()), m01(0.0f), m02(0.0f),
    m10(0.0f), m11(diagonal.GetY()), m12(0.0f),
    m20(0.0f), m21(0.0f), m22(diagonal.GetZ()) {}

inline Mat3::Mat3() : 
    m00(0.0f), m01(0.0f), m02(0.0f),
    m10(0.0f), m11(0.0f), m12(0.0f),
    m20(0.0f), m21(0.0f), m22(0.0f) {}

inline Mat3::Mat3(const Mat3& other) :
    m00(other.m00), m01(other.m01), m02(other.m02),
    m10(other.m10), m11(other.m11), m12(other.m12),
    m20(other.m20), m21(other.m21), m22(other.m22) {}

inline Mat3::Mat3(float _m00, float _m01, float _m02,
                  float _m10, float _m11, float _m12,
                  float _m20, float _m21, float _m22) :
    m00(_m00), m01(_m01), m02(_m02),
    m10(_m10), m11(_m11), m12(_m12),
    m20(_m20), m21(_m21), m22(_m22) {}

inline Mat3 Mat3::Identity() {
    return Mat3(1.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 1.0f);
}

inline Mat3 Mat3::Zero() {
    return Mat3();
}

inline Mat3& Mat3::operator=(const Mat3& other) {
    if (this != &other) {
        m00 = other.m00; m01 = other.m01; m02 = other.m02;
        m10 = other.m10; m11 = other.m11; m12 = other.m12;
        m20 = other.m20; m21 = other.m21; m22 = other.m22;
    }
    return *this;
}

inline Mat3 Mat3::operator+(const Mat3& other) const {
    return Mat3(m00 + other.m00, m01 + other.m01, m02 + other.m02,
                m10 + other.m10, m11 + other.m11, m12 + other.m12,
                m20 + other.m20, m21 + other.m21, m22 + other.m22);
}

inline Mat3 Mat3::operator-(const Mat3& other) const {
    return Mat3(m00 - other.m00, m01 - other.m01, m02 - other.m02,
                m10 - other.m10, m11 - other.m11, m12 - other.m12,
                m20 - other.m20, m21 - other.m21, m22 - other.m22);
}

inline Mat3 Mat3::operator*(float scalar) const {
    return Mat3(m00 * scalar, m01 * scalar, m02 * scalar,
                m10 * scalar, m11 * scalar, m12 * scalar,
                m20 * scalar, m21 * scalar, m22 * scalar);
}

inline Mat3 Mat3::operator/(float scalar) const {
    float invScalar = 1.0f / scalar;
    return Mat3(m00 * invScalar, m01 * invScalar, m02 * invScalar,
                m10 * invScalar, m11 * invScalar, m12 * invScalar,
                m20 * invScalar, m21 * invScalar, m22 * invScalar);
}

inline Mat3 Mat3::operator-() const {
    return Mat3(-m00, -m01, -m02,
                -m10, -m11, -m12,
                -m20, -m21, -m22);
}

inline bool Mat3::operator!=(const Mat3& other) const {
    return !(*this == other);
}

inline float Mat3::trace() const {
    return m00 + m11 + m22;
}

inline void Mat3::makeIdentity() {
    *this = Identity();
}

inline void Mat3::makeZero() {
    *this = Zero();
}

inline void Mat3::scale(float scalar) {
    *this *= scalar;
}

inline Mat3 operator*(float scalar, const Mat3& matrix) {
    return matrix * scalar;
}

inline bool Mat3::isEqual(float a, float b, float tolerance) const {
    return std::abs(a - b) <= tolerance;
}
}
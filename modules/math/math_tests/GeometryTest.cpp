#include <gtest/gtest.h>
#include <cmath>
#include "Mat3.hpp"
#include "Vector3.hpp"

using namespace math;

TEST(Mat3Test, ConstructorRowsColumns) {
    // Create three vectors
    Vector3 v0(1.0f, 2.0f, 3.0f);
    Vector3 v1(4.0f, 5.0f, 6.0f);
    Vector3 v2(7.0f, 8.0f, 9.0f);

    // As rows
    Mat3 mRows = Mat3::FromRows(v0, v1, v2);
    EXPECT_FLOAT_EQ(mRows.m00, 1.0f);
    EXPECT_FLOAT_EQ(mRows.m01, 2.0f);
    EXPECT_FLOAT_EQ(mRows.m02, 3.0f);
    EXPECT_FLOAT_EQ(mRows.m10, 4.0f);
    EXPECT_FLOAT_EQ(mRows.m11, 5.0f);
    EXPECT_FLOAT_EQ(mRows.m12, 6.0f);
    EXPECT_FLOAT_EQ(mRows.m20, 7.0f);
    EXPECT_FLOAT_EQ(mRows.m21, 8.0f);
    EXPECT_FLOAT_EQ(mRows.m22, 9.0f);

    // As columns
    Mat3 mCols = Mat3::FromColumns(v0, v1, v2);
    EXPECT_FLOAT_EQ(mCols.m00, 1.0f);
    EXPECT_FLOAT_EQ(mCols.m01, 4.0f);
    EXPECT_FLOAT_EQ(mCols.m02, 7.0f);
    EXPECT_FLOAT_EQ(mCols.m10, 2.0f);
    EXPECT_FLOAT_EQ(mCols.m11, 5.0f);
    EXPECT_FLOAT_EQ(mCols.m12, 8.0f);
    EXPECT_FLOAT_EQ(mCols.m20, 3.0f);
    EXPECT_FLOAT_EQ(mCols.m21, 6.0f);
    EXPECT_FLOAT_EQ(mCols.m22, 9.0f);
}

TEST(Mat3Test, DiagonalConstructor) {
    Vector3 diag(3.0f, 4.0f, 5.0f);
    Mat3 mDiagonal = Mat3::Diagonal(diag);
    
    EXPECT_FLOAT_EQ(mDiagonal.m00, 3.0f);
    EXPECT_FLOAT_EQ(mDiagonal.m11, 4.0f);
    EXPECT_FLOAT_EQ(mDiagonal.m22, 5.0f);
    
    // Off-diagonal elements should be zero
    EXPECT_FLOAT_EQ(mDiagonal.m01, 0.0f);
    EXPECT_FLOAT_EQ(mDiagonal.m02, 0.0f);
    EXPECT_FLOAT_EQ(mDiagonal.m10, 0.0f);
    EXPECT_FLOAT_EQ(mDiagonal.m12, 0.0f);
    EXPECT_FLOAT_EQ(mDiagonal.m20, 0.0f);
    EXPECT_FLOAT_EQ(mDiagonal.m21, 0.0f);
}

TEST(Mat3Test, AdditionSubtractionOperators) {
    Mat3 m1(1, 2, 3,
            4, 5, 6,
            7, 8, 9);
    Mat3 m2(9, 8, 7,
            6, 5, 4,
            3, 2, 1);

    Mat3 mAdd = m1 + m2;
    EXPECT_FLOAT_EQ(mAdd.m00, 10);
    EXPECT_FLOAT_EQ(mAdd.m11, 10);
    EXPECT_FLOAT_EQ(mAdd.m22, 10);

    Mat3 mSub = m1 - m2;
    EXPECT_FLOAT_EQ(mSub.m00, -8);
    EXPECT_FLOAT_EQ(mSub.m11, 0);
    EXPECT_FLOAT_EQ(mSub.m22, 8);
}

TEST(Mat3Test, ScalarMultiplicationDivision) {
    Mat3 m(1, 2, 3,
           4, 5, 6,
           7, 8, 9);
    
    float scalar = 2.0f;
    Mat3 mScaled = m * scalar;
    EXPECT_FLOAT_EQ(mScaled.m00, 2);
    EXPECT_FLOAT_EQ(mScaled.m11, 10);
    EXPECT_FLOAT_EQ(mScaled.m22, 18);

    Mat3 mDiv = m / scalar;
    EXPECT_FLOAT_EQ(mDiv.m00, 0.5f);
    EXPECT_FLOAT_EQ(mDiv.m11, 2.5f);
    EXPECT_FLOAT_EQ(mDiv.m22, 4.5f);

}

TEST(Mat3Test, UnaryNegationOperator) {
    Mat3 m(1, 2, 3,
           4, 5, 6,
           7, 8, 9);
    Mat3 neg = -m;
    EXPECT_FLOAT_EQ(neg.m00, -1);
    EXPECT_FLOAT_EQ(neg.m11, -5);
    EXPECT_FLOAT_EQ(neg.m22, -9);
}

TEST(Mat3Test, TraceIdentityZero) {
    // Create a matrix
    Mat3 m(1, 0, 0,
           0, 2, 0,
           0, 0, 3);
    
    EXPECT_FLOAT_EQ(m.trace(), 6);
    
    // Test makeIdentity and makeZero methods
    m.makeZero();
    EXPECT_FLOAT_EQ(m.m00, 0);
    EXPECT_FLOAT_EQ(m.m11, 0);
    EXPECT_FLOAT_EQ(m.m22, 0);

    m.makeIdentity();
    // Identity matrix: 1 on diagonal, 0 otherwise
    EXPECT_FLOAT_EQ(m.m00, 1);
    EXPECT_FLOAT_EQ(m.m11, 1);
    EXPECT_FLOAT_EQ(m.m22, 1);
    EXPECT_FLOAT_EQ(m.m01, 0);
    EXPECT_FLOAT_EQ(m.m02, 0);
    EXPECT_FLOAT_EQ(m.m10, 0);
    EXPECT_FLOAT_EQ(m.m12, 0);
    EXPECT_FLOAT_EQ(m.m20, 0);
    EXPECT_FLOAT_EQ(m.m21, 0);
}

TEST(Mat3Test, ScaleInPlace) {
    Mat3 m(1, 2, 3,
           4, 5, 6,
           7, 8, 9);
    m.scale(3.0f);
    EXPECT_FLOAT_EQ(m.m00, 3);
    EXPECT_FLOAT_EQ(m.m11, 15);
    EXPECT_FLOAT_EQ(m.m22, 27);
}

TEST(Mat3Test, CrossProductMatrix) {
    Vector3 v(1.0f, 2.0f, 3.0f);
    Mat3 crossM = Mat3::CrossProductMatrix(v);

    // For a vector [a, b, c], the skew symmetric matrix should be:
    // [  0   -c    b ]
    // [  c    0   -a ]
    // [ -b    a    0 ]
    EXPECT_FLOAT_EQ(crossM.m00,  0.0f);
    EXPECT_FLOAT_EQ(crossM.m01, -3.0f);
    EXPECT_FLOAT_EQ(crossM.m02,  2.0f);
    EXPECT_FLOAT_EQ(crossM.m10,  3.0f);
    EXPECT_FLOAT_EQ(crossM.m11,  0.0f);
    EXPECT_FLOAT_EQ(crossM.m12, -1.0f);
    EXPECT_FLOAT_EQ(crossM.m20, -2.0f);
    EXPECT_FLOAT_EQ(crossM.m21,  1.0f);
    EXPECT_FLOAT_EQ(crossM.m22,  0.0f);
}

TEST(Mat3Test, OuterProduct) {
    Vector3 u(1.0f, 2.0f, 3.0f);
    Vector3 v(4.0f, 5.0f, 6.0f);
    Mat3 outer = Mat3::OuterProduct(u, v);

    EXPECT_FLOAT_EQ(outer.m00, 1.0f * 4.0f);
    EXPECT_FLOAT_EQ(outer.m01, 1.0f * 5.0f);
    EXPECT_FLOAT_EQ(outer.m02, 1.0f * 6.0f);
    EXPECT_FLOAT_EQ(outer.m10, 2.0f * 4.0f);
    EXPECT_FLOAT_EQ(outer.m11, 2.0f * 5.0f);
    EXPECT_FLOAT_EQ(outer.m12, 2.0f * 6.0f);
    EXPECT_FLOAT_EQ(outer.m20, 3.0f * 4.0f);
    EXPECT_FLOAT_EQ(outer.m21, 3.0f * 5.0f);
    EXPECT_FLOAT_EQ(outer.m22, 3.0f * 6.0f);
}

TEST(Mat3Test, AssignmentOperator) {
    Mat3 m1(1, 2, 3,
            4, 5, 6,
            7, 8, 9);
    Mat3 m2 = m1;
    EXPECT_FLOAT_EQ(m2.m00, 1);
    EXPECT_FLOAT_EQ(m2.m11, 5);
    EXPECT_FLOAT_EQ(m2.m22, 9);

    m2 = Mat3(-1, -2, -3,
              -4, -5, -6,
              -7, -8, -9);
    EXPECT_FLOAT_EQ(m2.m00, -1);
    EXPECT_FLOAT_EQ(m2.m11, -5);
    EXPECT_FLOAT_EQ(m2.m22, -9);
}

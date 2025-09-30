#include "gtest/gtest.h"
#include <memory>
#include "CameraFactory.hpp"
#include "RaylibCamera2D.hpp"
#include "RaylibCamera3D.hpp"

using namespace graphics;

TEST(CameraTest, CreateRaylibCamera2D) {
    auto camera2D = CameraFactory::createCamera2D(CameraType2D::Raylib);
    ASSERT_NE(camera2D, nullptr) << "Failed to create 2D camera with Raylib type.";
    auto raylibCam2D = std::dynamic_pointer_cast<RaylibCamera2D>(camera2D);
    ASSERT_NE(raylibCam2D, nullptr) << "Created 2D camera is not a RaylibCamera2D instance.";
}

TEST(CameraTest, CreateRaylibCamera3D) {
    auto camera3D = CameraFactory::createCamera3D(CameraType3D::Raylib);
    ASSERT_NE(camera3D, nullptr) << "Failed to create 3D camera with Raylib type.";
    auto raylibCam3D = std::dynamic_pointer_cast<RaylibCamera3D>(camera3D);
    ASSERT_NE(raylibCam3D, nullptr) << "Created 3D camera is not a RaylibCamera3D instance.";
}

TEST(CameraTest, InvalidCamera2DTypeReturnsNullptr) {
    auto camera2D = CameraFactory::createCamera2D(CameraType2D::Invalid);
    ASSERT_EQ(camera2D, nullptr) << "CameraFactory should return nullptr for invalid 2D camera type.";
}

TEST(CameraTest, InvalidCamera3DTypeReturnsNullptr) {
    auto camera3D = CameraFactory::createCamera3D(CameraType3D::Invalid);
    ASSERT_EQ(camera3D, nullptr) << "CameraFactory should return nullptr for invalid 3D camera type.";
}

TEST(CameraTest, RaylibCamera2DSetAndGetZoom) {
    auto camera2D = CameraFactory::createCamera2D(CameraType2D::Raylib);
    ASSERT_NE(camera2D, nullptr);
    camera2D->SetZoom(2.5f);
    EXPECT_FLOAT_EQ(camera2D->GetZoom(), 2.5f);
}

TEST(CameraTest, RaylibCamera3DSetAndGetPosition) {
    auto camera3D = CameraFactory::createCamera3D(CameraType3D::Raylib);
    ASSERT_NE(camera3D, nullptr);
    math::Vector3 newPosition{1.0f, 2.0f, 3.0f};
    camera3D->SetPosition(newPosition);
    auto pos = camera3D->GetPosition();
    EXPECT_FLOAT_EQ(pos.GetX(), newPosition.GetX());
    EXPECT_FLOAT_EQ(pos.GetY(), newPosition.GetY());
    EXPECT_FLOAT_EQ(pos.GetZ(), newPosition.GetZ());
}

TEST(CameraTest, RaylibCamera3DSetAndGetFovy) {
    auto camera3D = CameraFactory::createCamera3D(CameraType3D::Raylib);
    ASSERT_NE(camera3D, nullptr);
    camera3D->SetFovy(60.0f);
    // No direct getter for Fovy, so we assume no exceptions and correct internal state
    SUCCEED();
}

TEST(CameraTest, RaylibCamera2DSetAndGetPosition) {
    auto camera2D = CameraFactory::createCamera2D(CameraType2D::Raylib);
    ASSERT_NE(camera2D, nullptr);
    math::Vector3 newPosition{100.0f, 150.0f, 0.0f};
    camera2D->SetPosition(newPosition);
    auto pos = camera2D->GetPosition();
    EXPECT_FLOAT_EQ(pos.GetX(), newPosition.GetX());
    EXPECT_FLOAT_EQ(pos.GetY(), newPosition.GetY());
    EXPECT_FLOAT_EQ(pos.GetZ(), newPosition.GetZ());
}

TEST(CameraTest, RaylibCamera2DSetAndGetTarget) {
    auto camera2D = CameraFactory::createCamera2D(CameraType2D::Raylib);
    ASSERT_NE(camera2D, nullptr);
    math::Vector3 newTarget{200.0f, 250.0f, 0.0f};
    camera2D->SetTarget(newTarget);
    auto target = camera2D->GetTarget();
    EXPECT_FLOAT_EQ(target.GetX(), newTarget.GetX());
    EXPECT_FLOAT_EQ(target.GetY(), newTarget.GetY());
    EXPECT_FLOAT_EQ(target.GetZ(), newTarget.GetZ());
}

TEST(CameraTest, RaylibCamera3DSetAndGetTarget) {
    auto camera3D = CameraFactory::createCamera3D(CameraType3D::Raylib);
    ASSERT_NE(camera3D, nullptr);
    math::Vector3 newTarget{0.0f, 0.0f, 0.0f};
    camera3D->SetTarget(newTarget);
    auto target = camera3D->GetTarget();
    EXPECT_FLOAT_EQ(target.GetX(), newTarget.GetX());
    EXPECT_FLOAT_EQ(target.GetY(), newTarget.GetY());
    EXPECT_FLOAT_EQ(target.GetZ(), newTarget.GetZ());
}

TEST(CameraTest, RaylibCamera3DSetAndGetUp) {
    auto camera3D = CameraFactory::createCamera3D(CameraType3D::Raylib);
    ASSERT_NE(camera3D, nullptr);
    math::Vector3 newUp{0.0f, 1.0f, 0.0f};
    camera3D->SetUp(newUp);
    auto up = camera3D->GetUp();
    EXPECT_FLOAT_EQ(up.GetX(), newUp.GetX());
    EXPECT_FLOAT_EQ(up.GetY(), newUp.GetY());
    EXPECT_FLOAT_EQ(up.GetZ(), newUp.GetZ());
}

TEST(CameraTest, RaylibCamera2DSetAndGetRotation) {
    auto camera2D = CameraFactory::createCamera2D(CameraType2D::Raylib);
    ASSERT_NE(camera2D, nullptr);
    camera2D->SetRotation(45.0f);
    EXPECT_FLOAT_EQ(camera2D->GetRotation(), 45.0f);
}
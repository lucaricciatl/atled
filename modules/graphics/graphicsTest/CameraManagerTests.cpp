#include "gtest/gtest.h"
#include <memory>
#include "CameraManager.hpp"
#include "ICamera.hpp"
#include "Vector3.hpp"
#include "raylib.hpp"

namespace {

// A fake camera implementation for testing purposes.
class FakeCamera : public graphics::ICamera {
public:
    // Default initialization for test values.
    FakeCamera()
        : mPosition(0.0f, 0.0f, 0.0f),
          mTarget(0.0f, 0.0f, 0.0f),
          mUp(0.0f, 1.0f, 0.0f),
          mZoom(1.0f),
          mRotation(0.0f),
          mFovy(45.0f),
          mProjection(raylib::CAMERA_PERSPECTIVE),
          beginCalled(false),
          endCalled(false) {}

    void BeginCamera() override { beginCalled = true; }
    void UpdateCamera() override {}
    void EndCamera() override { endCalled = true; }
    
    void SetPosition(math::Vector3 position) override { mPosition = position; }
    math::Vector3 GetPosition() const override { return mPosition; }

    void SetTarget(math::Vector3 target) override { mTarget = target; }
    math::Vector3 GetTarget() const override { return mTarget; }

    void SetUp(math::Vector3 up) override { mUp = up; }
    math::Vector3 GetUp() const override { return mUp; }

    void SetZoom(float zoom) override { mZoom = zoom; }
    float GetZoom() const override { return mZoom; }

    void SetRotation(float rotation) override { mRotation = rotation; }
    float GetRotation() const override { return mRotation; }

    void SetFovy(float aFovy) override { mFovy = aFovy; }
    void SetCameraProjection(raylib::CameraProjection aProjection) override { mProjection = aProjection; }

    // For test purposes
    bool beginCalled;
    bool endCalled;

private:
    math::Vector3 mPosition;
    math::Vector3 mTarget;
    math::Vector3 mUp;
    float mZoom;
    float mRotation;
    float mFovy;
    raylib::CameraProjection mProjection;
};

} // end anonymous namespace

// Test that the active camera is set automatically when a camera is added.
TEST(CameraManagerTest, AddAndGetActiveCamera) {
    graphics::CameraManager manager;
    auto camera1 = std::make_shared<FakeCamera>();
    auto camera2 = std::make_shared<FakeCamera>();

    // Initially no cameras so active camera is nullptr.
    ASSERT_EQ(manager.GetActiveCamera(), nullptr);

    manager.AddCamera(camera1);
    // After adding the first camera, it becomes the active camera.
    ASSERT_EQ(manager.GetActiveCamera(), camera1);

    manager.AddCamera(camera2);
    // Still, the active camera remains as the first camera added.
    ASSERT_EQ(manager.GetActiveCamera(), camera1);

    // Change active camera by index.
    manager.SetActiveCamera(1);
    ASSERT_EQ(manager.GetActiveCamera(), camera2);
}

// Test setting and getting camera position through the manager.
TEST(CameraManagerTest, SetAndGetCameraPosition) {
    graphics::CameraManager manager;
    auto fake = std::make_shared<FakeCamera>();
    manager.AddCamera(fake);

    math::Vector3 newPosition(10.0f, 20.0f, 30.0f);
    manager.SetCameraPosition(newPosition);
    auto pos = manager.GetCameraPosition();
    EXPECT_FLOAT_EQ(pos.GetX(), newPosition.GetX());
    EXPECT_FLOAT_EQ(pos.GetY(), newPosition.GetY());
    EXPECT_FLOAT_EQ(pos.GetZ(), newPosition.GetZ());
}

// Test setting and getting camera target through the manager.
TEST(CameraManagerTest, SetAndGetCameraTarget) {
    graphics::CameraManager manager;
    auto fake = std::make_shared<FakeCamera>();
    manager.AddCamera(fake);

    math::Vector3 newTarget(5.0f, 15.0f, 25.0f);
    manager.SetCameraTarget(newTarget);
    auto target = manager.GetCameraTarget();
    EXPECT_FLOAT_EQ(target.GetX(), newTarget.GetX());
    EXPECT_FLOAT_EQ(target.GetY(), newTarget.GetY());
    EXPECT_FLOAT_EQ(target.GetZ(), newTarget.GetZ());
}

// Test begin and end active camera calls.
TEST(CameraManagerTest, BeginAndEndActiveCamera) {
    graphics::CameraManager manager;
    auto fake = std::make_shared<FakeCamera>();
    manager.AddCamera(fake);

    // Before calling, flags should be false.
    EXPECT_FALSE(fake->beginCalled);
    EXPECT_FALSE(fake->endCalled);

    manager.BeginActiveCamera();
    EXPECT_TRUE(fake->beginCalled);

    manager.EndActiveCamera();
    EXPECT_TRUE(fake->endCalled);
}

// Test setting and getting rotation and zoom.
TEST(CameraManagerTest, SetAndGetRotationAndZoom) {
    graphics::CameraManager manager;
    auto fake = std::make_shared<FakeCamera>();
    manager.AddCamera(fake);

    manager.SetCameraRotation(45.0f);
    EXPECT_FLOAT_EQ(manager.GetCameraRotation(), 45.0f);

    manager.SetCameraZoom(3.5f);
    EXPECT_FLOAT_EQ(manager.GetCameraZoom(), 3.5f);
}

// Test camera offset and target X/Y modifications.
TEST(CameraManagerTest, SetCameraOffsetAndTargetComponents) {
    graphics::CameraManager manager;
    auto fake = std::make_shared<FakeCamera>();
    manager.AddCamera(fake);

    // Set and test offset X
    manager.SetCameraOffsetX(100.0f);
    EXPECT_FLOAT_EQ(manager.GetCameraOffsetX(), 100.0f);

    // Set and test offset Y
    manager.SetCameraOffsetY(200.0f);
    EXPECT_FLOAT_EQ(manager.GetCameraOffsetY(), 200.0f);

    // Set and test target X
    manager.SetCameraTargetX(300.0f);
    EXPECT_FLOAT_EQ(manager.GetCameraTargetX(), 300.0f);

    // Set and test target Y
    manager.SetCameraTargetY(400.0f);
    EXPECT_FLOAT_EQ(manager.GetCameraTargetY(), 400.0f);
}

// Test the UpdateCameras function calls BeginCamera on all cameras.
TEST(CameraManagerTest, UpdateCamerasCallsBeginCamera) {
    graphics::CameraManager manager;
    auto fake1 = std::make_shared<FakeCamera>();
    auto fake2 = std::make_shared<FakeCamera>();
    manager.AddCamera(fake1);
    manager.AddCamera(fake2);

    // Reset flags
    fake1->beginCalled = false;
    fake2->beginCalled = false;

    manager.UpdateCameras();
    EXPECT_TRUE(fake1->beginCalled);
    EXPECT_TRUE(fake2->beginCalled);
}

TEST(CameraManagerInitializationTest, DefaultActiveCameraIsNullptr) {
    graphics::CameraManager manager;
    // On initialization, no camera has been added so the active camera should be nullptr.
    ASSERT_EQ(manager.GetActiveCamera(), nullptr);
}

TEST(CameraManagerInitializationTest, DefaultCameraParameters) {
    graphics::CameraManager manager;
    // When no active camera is set, getter functions return default values.
    // Rotation returns 0.0f and zoom returns 1.0f.
    EXPECT_FLOAT_EQ(manager.GetCameraRotation(), 0.0f);
    EXPECT_FLOAT_EQ(manager.GetCameraZoom(), 1.0f);
    // Offsets and target components return 0.0f.
    EXPECT_FLOAT_EQ(manager.GetCameraOffsetX(), 0.0f);
    EXPECT_FLOAT_EQ(manager.GetCameraOffsetY(), 0.0f);
    EXPECT_FLOAT_EQ(manager.GetCameraTargetX(), 0.0f);
    EXPECT_FLOAT_EQ(manager.GetCameraTargetY(), 0.0f);
}


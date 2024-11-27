#include "Cube.hpp"
using namespace raylib;

namespace graphics {

	Cube::Cube(float width, float height, float length)
		: mDimensions{ width, height, length }, mCenterPos{ 0.0f, 0.0f, 0.0f } {}

	void Cube::Draw() {

		auto gPos = ComputeGlobalPosition(mCenterPos);
		if (ShapeIsEnabled) {

			raylib::DrawCube(gPos, mDimensions.x, mDimensions.y, mDimensions.z, mColor);
		}
		if (WireframeIsEnabled) {
			raylib::DrawCubeWires(gPos, mDimensions.x, mDimensions.y, mDimensions.z, mWireframeColor);
		}
	}

	// Setters for dimensions
	void Cube::SetWidth(float width) {
		mDimensions.x = width;
	}

	void Cube::SetHeight(float height) {
		mDimensions.y = height;
	}

	void Cube::SetLength(float length) {
		mDimensions.z = length;
	}

	// Getters for dimensions
	float Cube::GetWidth() const {
		return mDimensions.x;
	}

	float Cube::GetHeight() const {
		return mDimensions.y;
	}

	float Cube::GetLength() const {
		return mDimensions.z;
	}

	// Setter for center position
	void Cube::SetCenterPos(const Vector3& centerPos) {
		mCenterPos = centerPos;
	}

	// Getter for center position
	Vector3 Cube::GetCenterPos() const {
		return mCenterPos;
	}



}  // namespace graphics

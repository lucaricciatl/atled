#include "Model3D.hpp"

namespace graphics{
Color Model3D::GetWireframeColor() const {
	return mWireframeColor;
}

// Enable wireframe rendering
void Model3D::EnableWireframe() {
	WireframeIsEnabled = true;
}

// Disable wireframe rendering
void Model3D::DisableWireframe() {
	WireframeIsEnabled = false;
}

// Enable wireframe rendering
void Model3D::EnableShape() {
	ShapeIsEnabled = true;
}

// Disable wireframe rendering
void Model3D::DisableShape() {
	ShapeIsEnabled = false;
}

// Set wireframe color
void Model3D::SetWireframeColor(Color aColor) {
	mWireframeColor = aColor;
}

// Setter for color
void Model3D::SetColor(const Color& color) {
	mColor = color;
}

// Getter for color
Color Model3D::GetColor() const {
	return mColor;
}

}
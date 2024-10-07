#include "graphicsImpl.hpp"
#include <iostream>
#include "Polygon.hpp"
#include "Arc.hpp"
#include "Circle.hpp"
#include "shapeFactory.hpp"
using namespace graphics;

namespace {
float times = 0.0f;  // Initialize time variable
}  // namespace


void GraphicsManagerImpl::Init() {  }


void GraphicsManagerImpl::Render() {
  auto arc = ShapeFactory::createArc();
  arc->setCenter(Coordinates2D(200, 200));
  arc->setStartAngle(10);
  arc->setEndAngle(30);
  arc->setRadius(100);
  arc->SetThickness(12);
  auto col= Color(244, 244, 9, 50);
  arc->SetColor(col);
  AddArc(1, arc);

  
  auto circle = ShapeFactory::createCircle();
  circle->setCenter(Coordinates2D(200, 400));
  circle->SetRadius(100);
  circle->setColor(col);
  AddCircle(2, circle);

  BeginDrawing();

  DrawLayer(1);
  DrawLayer(2);
  EndDrawing();
}
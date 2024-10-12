#include "graphicsImpl.hpp"
#include <iostream>
#include "Polygon.hpp"
#include "Arc.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Model2DFactory.hpp"
using namespace graphics;

namespace {
float times = 0.0f;  // Initialize time variable
}  // namespace


void GraphicsManagerImpl::Init() {  
  auto ctx = GetGraphicsContext();
  ctx->SetSize(900, 900);
  ctx->SetTitle("Window");
  auto configs = graphics::GfxConfig({FLAG_WINDOW_RESIZABLE, FLAG_VSYNC_HINT,
                                      FLAG_WINDOW_HIGHDPI, FLAG_MSAA_4X_HINT});
  SetConfigs(configs);
}

void GraphicsManagerImpl::Render() {
  auto arc = Model2DFactory::CreateArc();
  arc->SetCenter(Coordinates2D(200, 200));
  arc->SetStartAngle(-180);
  arc->SetEndAngle(0);
  arc->SetRadius(100);
  arc->SetThickness(12);
  auto col= Color(244, 244, 9, 50);
  arc->SetColor(col);
  AddArc(1, arc);
  
  auto circle = Model2DFactory::CreateCircle();
  circle->SetCenter(Coordinates2D(200, 400));
  circle->SetRadius(100);
  circle->SetColor(col);
  AddCircle(2, circle);

  auto rectangle = Model2DFactory::CreateRectangle();
  rectangle->SetUpperLeft(Coordinates2D(200, 700));
  rectangle->SetBottomRight(Coordinates2D(400, 900));
  rectangle->SetColor(col);
  rectangle->SetRotation(20);
  AddRectangle(3, rectangle);

  BeginDrawing();

  DrawLayer(1);
  DrawLayer(2);
  DrawLayer(3);

  EndDrawing();
}
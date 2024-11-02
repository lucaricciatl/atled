#include "graphicsImpl.hpp"
#include <iostream>
#include "Polygon.hpp"
#include "Arc.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Model2DFactory.hpp"
#include "Point2D.hpp"

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

  auto line = Model2DFactory::CreateLine();
  line->SetStartPoint(Coordinates2D(500, 500));
  line->SetColor(col);
  line->SetEndPoint(Coordinates2D(500, 600));
  line->SetThickness(3);
  AddLine(4, line);

  // Add the polyline here
  auto polyline = Model2DFactory::CreatePolyline();
  std::vector<Coordinates2D> points = {
      Coordinates2D(600, 600), Coordinates2D(700, 650), Coordinates2D(650, 700),
      Coordinates2D(700, 750)};
  polyline->SetPoints(points);
  polyline->SetThickness(5);
  polyline->SetColor(col);
  AddPolyline(5, polyline);

  auto triangle = Model2DFactory::CreateTriangle();
  triangle->SetPoints(
    Coordinates2D(850, 600),
    Coordinates2D(800, 500),
    Coordinates2D(750, 600)
  );
  triangle->SetColor(col);
  AddTriangle(6, triangle);

  auto polygon = Model2DFactory::CreatePolygon();
  const std::vector<Coordinates2D> polygonPoints = {
    Coordinates2D(300, 300),
    Coordinates2D(350, 400),
    Coordinates2D(400, 350),
    Coordinates2D(450, 400),
    Coordinates2D(500, 300),
    Coordinates2D(400, 250)
  };
  polygon->SetPoints(polygonPoints);
  polygon->SetColor(col);
  AddPolygon(7, polygon);

  BeginDrawing();

  DrawLayer(1);
  DrawLayer(2);
  DrawLayer(3);
  DrawLayer(4);
  DrawLayer(5);
  DrawLayer(6);
  DrawLayer(7);

  EndDrawing();
}
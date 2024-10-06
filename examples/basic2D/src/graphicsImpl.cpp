#include "graphicsImpl.hpp"
#include <iostream>
#include "Polygon.hpp"
#include "Arc.hpp"

using namespace graphics;

namespace {
float times = 0.0f;  // Initialize time variable
}  // namespace


void GraphicsManagerImpl::Init() {
  mContext->mLayerManager.AddLayer(1);
  mContext->mLayerManager.AddLayer(2);
  auto layer = mContext->mLayerManager.GetLayerById(1);
  auto layer2 = mContext->mLayerManager.GetLayerById(2);
  auto bm = layer->GetBufferManager();
  pb = bm->createBuffer(BufferType::POINT2D);
  lb = bm->createBuffer(BufferType::LINE2D);
  polyBuffer = bm->createBuffer(BufferType::POLY2D);
  polyBuffer2 = bm->createBuffer(BufferType::POLY2D);
}

// Define a function to add points
void addColoredPoint(std::vector<ColoredPoint2D>& points, int x, int y,
                     Color color) {
  points.emplace_back(x, y, color);
}

void GraphicsManagerImpl::Render() {
  if (mContext->isReady) {
    mContext->BeginDrawing();

    auto col = Color(0, 0, 0, 23);
    mContext->Clear(col);
    // 1. Draw a line with oscillating points
    {
      std::vector<ColoredPoint2D> linePoints;
      int x1 = 50, y1 = 50;
      int x2 = 250, y2 = 250;
      int numPoints = 200;  // Number of points along the line
      for (int i = 0; i <= numPoints; ++i) {
        float t = static_cast<float>(i) / numPoints;
        int x = static_cast<int>(x1 + t * (x2 - x1));
        int y = static_cast<int>(y1 + t * (y2 - y1));

        // Apply sinusoidal oscillation
        float oscillation =
            100.0f *
            sin(times + i * 0.1f);  // Amplitude and frequency of oscillation
        y += static_cast<int>(
            oscillation);  // Modify y-position with oscillation

        linePoints.emplace_back(x, y, RED);
      }
      pb->SetBuffer(linePoints);
      pb->DrawBuffer();
    }

    // 2. Draw an oscillating circle using lines
    {
      std::vector<ColoredPoint2D> circleLines;
      int centerX = 600, centerY = 600, radius = 100;
      int segments = 100;  // Number of segments to approximate the circle
      for (int i = 0; i < segments; ++i) {
        float theta2 = (PI * (i)) * 2 / segments;

        // Oscillate the radius
        float oscillatingRadius = radius + 100.0f * abs(sin(times));
        int x2 = static_cast<int>(centerX + oscillatingRadius * cos(theta2));
        int y2 = static_cast<int>(centerY + oscillatingRadius * sin(theta2));

        circleLines.emplace_back(x2, y2, GREEN);
      }
      circleLines.emplace_back(circleLines[0]);
      lb->SetBuffer(circleLines);
      lb->DrawBuffer();
    }

// Define colors
    const auto colorRed = RED;
    const auto colorBlue = BLUE;

    // Define the center, radius, and angles for the arc
    Coordinates2D arcCenter = {300, 300};  // Example center coordinates
    double arcRadius = 200.0;              // Example radius
    double startAngle = 0.0;               // Start angle in degrees
    double endAngle = 70.0;               // End angle in degrees
    double thickness = 70.0;                // End angle in degrees

    // Create an Arc object (this will generate the points for the arc)
    graphics::Arc arc(arcCenter, arcRadius, startAngle, endAngle,thickness, colorRed);

    arc.Draw();

    // Create polygons
    //graphics::Polygon polygon1(points2);

    // Add points to points3 (keeping this as is for the second polygon)
    std::vector<ColoredPoint2D> points3;
    addColoredPoint(points3, 200, 630, colorBlue);
    addColoredPoint(points3, 130, 920, colorBlue);
    addColoredPoint(points3, 500, 0, colorBlue);
    addColoredPoint(points3, 400, 300, colorBlue);


    // 3. Draw an oscillating irregular polygon
    
    // 4. Draw an oscillating irregular polygon

    mContext->EndDrawing();

    times += 0.1f;  // Increment time for oscillation
  }
}
#include "graphicsImpl.hpp"
#include <iostream>

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

void GraphicsManagerImpl::Render() {
  if (mContext->isReady) {
    mContext->Begin();
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

    std::vector<ColoredPoint2D> points2;
    auto colrt = RED;
    int x1 = static_cast<int>(400 + 200);
    int y1 = static_cast<int>(200 + 130);
    points2.emplace_back(x1, y1, colrt);
    int x2 = static_cast<int>(400 + 130);
    int y2 = static_cast<int>(200 + 120);
    points2.emplace_back(x2, y2, colrt);

    int x3 = static_cast<int>(400 + 100);
    int y3 = static_cast<int>(200 + 0);
    points2.emplace_back(x3, y3, colrt);

    int x4 = static_cast<int>(400 + 0);
    int y4 = static_cast<int>(200 + 100);
    points2.emplace_back(x4, y4, colrt);
    // Set the points buffer to the polygon buffer
    polyBuffer2->SetBuffer(points2);
    polyBuffer2->DrawBuffer();  // Draw the oscillating polygon

    // 3. Draw an oscillating irregular polygon
    {
      std::vector<ColoredPoint2D> points;
      auto colrt = RED;
      points.emplace_back(static_cast<int>(700 + 0), static_cast<int>(700 + 0),
                          colrt);  // Example points
      for (int i = 0; i < (53 * sin(times * 0.1)); ++i) {
        // Apply oscillation to the polygon points
        int x = static_cast<int>(700 + 100 * sin(2 * PI / 52 * i));
        int y = static_cast<int>(700 + 100 * cos(2 * PI / 52 * i));
        points.emplace_back(x, y, colrt);
      }

      // Set the points buffer to the polygon buffer
      polyBuffer->SetBuffer(points);
      polyBuffer->DrawBuffer();  // Draw the oscillating polygon
    }

    // 4. Draw an oscillating irregular polygon

    auto col = Color(0,0,0,23);
    mContext->Clear(col);
    mContext->End();

    times += 0.1f;  // Increment time for oscillation
  }
}
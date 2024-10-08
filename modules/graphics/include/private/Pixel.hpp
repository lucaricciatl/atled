#pragma once
#include "glwp.hpp"
#include "PointBuffer2D.hpp"

namespace graphics {

class Pixel {
 public:
  Pixel();

  // Funzione per disegnare tutti i punti nel buffer
  void Draw(const std::vector<ColoredPoint2D>& mPoints);

 private:
};

}  // namespace graphics
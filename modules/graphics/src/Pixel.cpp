#pragma once
#include "Pixel.hpp"  // Assicurati di includere il file che contiene la classe PointBuffer2D
#include "glwp.hpp"
#include "PointBuffer2D.hpp"

namespace graphics {



// Funzione per disegnare i punti nel buffer utilizzando Relib
void Pixel::Draw(const std::vector<ColoredPoint2D>& mPoints) {
  if (mPoints.empty()) {
    return;
  }

  // Itera su tutti i punti nel buffer
  for (auto p : mPoints) {
    // Usa il renderer di Relib per disegnare il punto
    // Qui ipotizzo che Relib abbia una funzione per disegnare pixel o punti 2D
    DrawPixel(static_cast<int>(p.x), static_cast<int>(p.y), p.color);
  }
}


}  // namespace graphics
#ifndef POLYGONBUFFER2D_HPP
#define POLYGONBUFFER2D_HPP

#include <vector>
#include "Polygon2DImpl.hpp"
#include "PointBuffer2D.hpp"
#include "Buffer2D.hpp"

namespace graphics {

class PolygonBuffer2D : public Buffer2D {
 public:
     void AddPoint(float aX, float aY);
    ColoredPoint2D GetPoint(size_t aIndex) const;
    void RemovePoint(size_t aIndex);
    void ClearBuffer();
    size_t GetSize() const noexcept;
    bool IsEmpty() const noexcept;
    std::vector<ColoredPoint2D> GetBuffer() const noexcept;
    void SetBuffer(std::vector<ColoredPoint2D> aBuffer);
    void LoadBuffer();
    void AppendToBuffer(const std::vector<ColoredPoint2D>& aPoints);
    void AppendToBuffer(ColoredPoint2D aPoint);
    void DrawBuffer() override;

private:
    std::vector<ColoredPoint2D> mBuffer;  // Buffer to store points
    Polygon2DImpl mPolygon;       // Polygon object for drawing
};

}  // namespace graphics

#endif  // POLYGONBUFFER2D_HPP

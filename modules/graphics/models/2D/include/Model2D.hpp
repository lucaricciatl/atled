#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include "raylib.hpp"
#include "Point2D.hpp"
#include "Model.hpp"
#include "Color.hpp"
namespace graphics
{
	using namespace raylib;

	class Model2D : public Model
	{
	public:
		virtual ~Model2D() = default;
		virtual void Draw() = 0;

		Color GetColor() const;
		double GetRotation() const;
		void SetColor(graphics::Color color);
		void SetRotation(double rotation);

	protected:
		Vector2 ComputeGlobalPosition(Coordinates2D aPosition)
		{
			auto framepos = frame->GetPosition();
            Vector2 globalPosition = {
                (float)framepos->GetX() + aPosition.x,
                (float)framepos->GetY() + aPosition.y,
            };
            return globalPosition;
        };
        graphics::Color mColor;
        double mRotation;
    };
} // namespace graphics
#endif // SHAPE_HPP

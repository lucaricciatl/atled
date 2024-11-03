#ifndef IRENDERSTRATEGY_HPP
#define IRENDERSTRATEGY_HPP

class Polygon; // Forward declaration

class IRenderStrategy {
public:
    virtual ~IRenderStrategy() = default;
    virtual void Render(const Model2D& model) const = 0;
};

#endif // IRENDERSTRATEGY_HPP

// Quantity.hpp

#ifndef QUANTITY_HPP
#define QUANTITY_HPP

#include "Dimensions.hpp"
#include <iostream>
#include <type_traits>

namespace Units {

template<typename Dimension, typename T = double>
class Quantity {
private:
    T value;

public:
    // Constructors
    explicit constexpr Quantity(T val) : value(val) {}

    // Accessor
    constexpr T getValue() const { return value; }

    // Unary plus and minus
    constexpr Quantity operator+() const { return *this; }
    constexpr Quantity operator-() const { return Quantity(-value); }

    // Compound assignment operators
    Quantity& operator+=(const Quantity& rhs) {
        value += rhs.value;
        return *this;
    }

    Quantity& operator-=(const Quantity& rhs) {
        value -= rhs.value;
        return *this;
    }

    Quantity& operator*=(T scalar) {
        value *= scalar;
        return *this;
    }

    Quantity& operator/=(T scalar) {
        value /= scalar;
        return *this;
    }

    // Friend functions for arithmetic operators
    template<typename D, typename U>
    friend constexpr Quantity<D, U> operator+(const Quantity<D, U>& lhs, const Quantity<D, U>& rhs);

    template<typename D, typename U>
    friend constexpr Quantity<D, U> operator-(const Quantity<D, U>& lhs, const Quantity<D, U>& rhs);

    template<typename D1, typename D2, typename U>
    friend constexpr Quantity<
        Dimension<
            D1::length + D2::length,
            D1::mass + D2::mass,
            D1::time + D2::time,
            D1::current + D2::current,
            D1::temperature + D2::temperature,
            D1::amount + D2::amount,
            D1::luminousIntensity + D2::luminousIntensity
        >,
        U
    > operator*(const Quantity<D1, U>& lhs, const Quantity<D2, U>& rhs);

    template<typename D1, typename D2, typename U>
    friend constexpr Quantity<
        Dimension<
            D1::length - D2::length,
            D1::mass - D2::mass,
            D1::time - D2::time,
            D1::current - D2::current,
            D1::temperature - D2::temperature,
            D1::amount - D2::amount,
            D1::luminousIntensity - D2::luminousIntensity
        >,
        U
    > operator/(const Quantity<D1, U>& lhs, const Quantity<D2, U>& rhs);

    // Scalar multiplication and division
    friend constexpr Quantity operator*(const Quantity& lhs, T scalar) {
        return Quantity(lhs.value * scalar);
    }

    friend constexpr Quantity operator*(T scalar, const Quantity& rhs) {
        return Quantity(scalar * rhs.value);
    }

    friend constexpr Quantity operator/(const Quantity& lhs, T scalar) {
        return Quantity(lhs.value / scalar);
    }

    // Comparison operators (only for same dimensions)
    friend constexpr bool operator==(const Quantity& lhs, const Quantity& rhs) {
        return lhs.value == rhs.value;
    }

    friend constexpr bool operator!=(const Quantity& lhs, const Quantity& rhs) {
        return lhs.value != rhs.value;
    }

    friend constexpr bool operator<(const Quantity& lhs, const Quantity& rhs) {
        return lhs.value < rhs.value;
    }

    friend constexpr bool operator>(const Quantity& lhs, const Quantity& rhs) {
        return lhs.value > rhs.value;
    }

    friend constexpr bool operator<=(const Quantity& lhs, const Quantity& rhs) {
        return lhs.value <= rhs.value;
    }

    friend constexpr bool operator>=(const Quantity& lhs, const Quantity& rhs) {
        return lhs.value >= rhs.value;
    }

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Quantity& qty) {
        os << qty.value;
        return os;
    }
};

} // namespace Units

#endif // QUANTITY_HPP

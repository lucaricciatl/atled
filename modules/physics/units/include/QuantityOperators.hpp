// QuantityOperators.hpp

#ifndef QUANTITYOPERATORS_HPP
#define QUANTITYOPERATORS_HPP

#include "Quantity.hpp"

namespace Units {

// Addition and Subtraction (only for same dimensions)
template<typename D, typename T>
constexpr Quantity<D, T> operator+(const Quantity<D, T>& lhs, const Quantity<D, T>& rhs) {
    return Quantity<D, T>(lhs.value + rhs.value);
}

template<typename D, typename T>
constexpr Quantity<D, T> operator-(const Quantity<D, T>& lhs, const Quantity<D, T>& rhs) {
    return Quantity<D, T>(lhs.value - rhs.value);
}

// Multiplication
template<typename D1, typename D2, typename T>
constexpr Quantity<
    Dimension<
        D1::length + D2::length,
        D1::mass + D2::mass,
        D1::time + D2::time,
        D1::current + D2::current,
        D1::temperature + D2::temperature,
        D1::amount + D2::amount,
        D1::luminousIntensity + D2::luminousIntensity
    >,
    T
> operator*(const Quantity<D1, T>& lhs, const Quantity<D2, T>& rhs) {
    return Quantity<
        Dimension<
            D1::length + D2::length,
            D1::mass + D2::mass,
            D1::time + D2::time,
            D1::current + D2::current,
            D1::temperature + D2::temperature,
            D1::amount + D2::amount,
            D1::luminousIntensity + D2::luminousIntensity
        >,
        T
    >(lhs.value * rhs.value);
}

// Division
template<typename D1, typename D2, typename T>
constexpr Quantity<
    Dimension<
        D1::length - D2::length,
        D1::mass - D2::mass,
        D1::time - D2::time,
        D1::current - D2::current,
        D1::temperature - D2::temperature,
        D1::amount - D2::amount,
        D1::luminousIntensity - D2::luminousIntensity
    >,
    T
> operator/(const Quantity<D1, T>& lhs, const Quantity<D2, T>& rhs) {
    return Quantity<
        Dimension<
            D1::length - D2::length,
            D1::mass - D2::mass,
            D1::time - D2::time,
            D1::current - D2::current,
            D1::temperature - D2::temperature,
            D1::amount - D2::amount,
            D1::luminousIntensity - D2::luminousIntensity
        >,
        T
    >(lhs.value / rhs.value);
}

} // namespace Units

#endif // QUANTITYOPERATORS_HPP

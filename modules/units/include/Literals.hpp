// Literals.hpp

#ifndef LITERALS_HPP
#define LITERALS_HPP

#include "Units.hpp"

namespace Units {

constexpr Quantity<Length> operator"" _m(long double val) {
    return Quantity<Length>(static_cast<double>(val));
}

constexpr Quantity<Length> operator"" _cm(long double val) {
    return Quantity<Length>(static_cast<double>(val) * 1e-2);
}

constexpr Quantity<Length> operator"" _km(long double val) {
    return Quantity<Length>(static_cast<double>(val) * 1e3);
}

constexpr Quantity<Mass> operator"" _kg(long double val) {
    return Quantity<Mass>(static_cast<double>(val));
}

constexpr Quantity<Mass> operator"" _g(long double val) {
    return Quantity<Mass>(static_cast<double>(val) * 1e-3);
}

constexpr Quantity<Time> operator"" _s(long double val) {
    return Quantity<Time>(static_cast<double>(val));
}

constexpr Quantity<Time> operator"" _ms(long double val) {
    return Quantity<Time>(static_cast<double>(val) * 1e-3);
}

constexpr Quantity<Current> operator"" _A(long double val) {
    return Quantity<Current>(static_cast<double>(val));
}

constexpr Quantity<Current> operator"" _mA(long double val) {
    return Quantity<Current>(static_cast<double>(val) * 1e-3);
}

constexpr Quantity<Temperature> operator"" _K(long double val) {
    return Quantity<Temperature>(static_cast<double>(val));
}

constexpr Quantity<Amount> operator"" _mol(long double val) {
    return Quantity<Amount>(static_cast<double>(val));
}

constexpr Quantity<LuminousIntensity> operator"" _cd(long double val) {
    return Quantity<LuminousIntensity>(static_cast<double>(val));
}

// User-defined literal for pixels
constexpr Quantity<Pixels> operator"" _px(unsigned long long val) {
    return Quantity<Pixels>(static_cast<double>(val));
}

} // namespace Units

#endif // LITERALS_HPP

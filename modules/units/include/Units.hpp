// Units.hpp

#ifndef UNITS_HPP
#define UNITS_HPP

#include "Quantity.hpp"
#include "QuantityOperators.hpp"

namespace Units {

// Base dimensions
using Dimensionless = Dimension<0, 0, 0, 0, 0, 0, 0>;
using Length = Dimension<1, 0, 0, 0, 0, 0, 0>;
using Mass = Dimension<0, 1, 0, 0, 0, 0, 0>;
using Time = Dimension<0, 0, 1, 0, 0, 0, 0>;
using Current = Dimension<0, 0, 0, 1, 0, 0, 0>;
using Temperature = Dimension<0, 0, 0, 0, 1, 0, 0>;
using Amount = Dimension<0, 0, 0, 0, 0, 1, 0>;
using LuminousIntensity = Dimension<0, 0, 0, 0, 0, 0, 1>;

// Derived dimensions
using Velocity = Dimension<1, 0, -1, 0, 0, 0, 0>;                 // L T^-1
using Acceleration = Dimension<1, 0, -2, 0, 0, 0, 0>;             // L T^-2
using Force = Dimension<1, 1, -2, 0, 0, 0, 0>;                    // M L T^-2
using Energy = Dimension<2, 1, -2, 0, 0, 0, 0>;                   // M L^2 T^-2
using Power = Dimension<2, 1, -3, 0, 0, 0, 0>;                    // M L^2 T^-3
using Charge = Dimension<0, 0, 1, 1, 0, 0, 0>;                    // T I
using Voltage = Dimension<2, 1, -3, -1, 0, 0, 0>;                 // M L^2 T^-3 I^-1
using Resistance = Dimension<2, 1, -3, -2, 0, 0, 0>;              // M L^2 T^-3 I^-2

// Custom dimensions (e.g., pixels)
using Pixels = Dimension<0, 0, 0, 0, 0, 0, 0>; // Dimensionless but can be distinguished via type

// Base unit constants
constexpr Quantity<Length> meters(1.0);
constexpr Quantity<Mass> kilograms(1.0);
constexpr Quantity<Time> seconds(1.0);
constexpr Quantity<Current> amperes(1.0);
constexpr Quantity<Temperature> kelvin(1.0);
constexpr Quantity<Amount> moles(1.0);
constexpr Quantity<LuminousIntensity> candelas(1.0);

// Prefixes
constexpr double milli = 1e-3;
constexpr double centi = 1e-2;
constexpr double kilo = 1e3;
constexpr double mega = 1e6;

// Common units
constexpr auto centimeters = centi * meters;
constexpr auto kilometers = kilo * meters;
constexpr auto grams = milli * kilograms;
constexpr auto milliamperes = milli * amperes;

// Custom units
constexpr Quantity<Pixels> pixel(1.0);

// Units for derived dimensions
constexpr auto newtons = kilograms * meters / (seconds * seconds);
constexpr auto joules = newtons * meters;
constexpr auto watts = joules / seconds;
constexpr auto coulombs = amperes * seconds;
constexpr auto volts = watts / amperes; // M L^2 T^-3 I^-1
constexpr auto ohms = volts / amperes;  // M L^2 T^-3 I^-2

} // namespace Units

#endif // UNITS_HPP

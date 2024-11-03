// Dimensions.hpp

#ifndef DIMENSIONS_HPP
#define DIMENSIONS_HPP

namespace Units {

// Base dimensions indices:
// L - Length
// M - Mass
// T - Time
// I - Electric Current
// Theta - Thermodynamic Temperature
// N - Amount of Substance
// J - Luminous Intensity

template<int L, int M, int T, int I, int Theta, int N, int J>
struct Dimension {
    static constexpr int length = L;
    static constexpr int mass = M;
    static constexpr int time = T;
    static constexpr int current = I;
    static constexpr int temperature = Theta;
    static constexpr int amount = N;
    static constexpr int luminousIntensity = J;
};

} // namespace Units

#endif // DIMENSIONS_HPP

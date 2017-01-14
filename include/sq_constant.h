#pragma once

namespace sqmath
{
// EPS
template < typename T >
constexpr T eps() { return static_cast<T>(1e-6); }

/// pi
template < typename T >
constexpr T pi() { return static_cast<T>(3.14159265358979323846); }

/// 2 * pi
template < typename T >
constexpr T piTimes2();

template<>
constexpr float piTimes2() { return 6.2831853071795862f; }

template<>
constexpr double piTimes2() { return 6.28318530717958647692; }

/// 1 / pi
template < typename T >
constexpr T oneOverPi() { return static_cast<T>(0.318309886183790671538); }

/// 1 / 2pi
template < typename T >
constexpr T oneOverPi2();

template<>
constexpr float oneOverPi2() { return 0.1591549430918953f; }

/// sqrt(2)
template< typename T >
constexpr T sqrt2();

template<>
constexpr float sqrt2() { return 1.4142135623730951f; }

template<>
constexpr double sqrt2() { return 1.41421356237309504880; }

} // end of namespace sqmath
// [EOF]

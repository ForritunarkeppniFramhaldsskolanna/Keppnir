#pragma once
#include <cstdint>

template <class T>
constexpr T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }

template <class T>
constexpr T myabs(T a) { return a < T(0) ? -a : a; };

std::istream& operator>>(std::istream& ins, __int128_t& x) {
    int64_t tmp;
    ins >> tmp;
    x = tmp;
    return ins;
}

std::ostream& operator<<(std::ostream& outs, const __int128_t& x) {
    int64_t tmp = x;
    outs << tmp;
    return outs;
}

template <typename T>
constexpr T EPS{ 0 };

template <>
constexpr float EPS<float> = 5e-6f;
template <>
constexpr double EPS<double> = 5e-6;
template <>
constexpr long double EPS<long double> = 5e-6L;

enum class intersection_t { none, one, infinite };

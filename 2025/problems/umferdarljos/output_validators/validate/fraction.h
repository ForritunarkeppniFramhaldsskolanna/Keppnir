#pragma once
#include <cmath>
#include <numeric>
#include <iostream>

template <class T>
constexpr T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }

template <class T>
struct fraction
{
    T n, d;
    constexpr fraction(T n_ = T(0), T d_ = T(1)) : n(n_), d(d_)
    {
        assert(d_ != 0);
        if (d < T(0))
            n = -n, d = -d;
        T g = gcd(n < 0 ? -n : n, d < 0 ? -d : d);
        n /= g, d /= g;
    }
    constexpr fraction(const fraction<T> &other)
        : n(other.n), d(other.d) {}
    constexpr fraction<T> operator-() const
    {
        return {-n, d};
    }
    constexpr fraction<T> operator+(const fraction<T> &other) const
    {
        return {n * other.d + other.n * d, d * other.d};
    }
    constexpr fraction<T> operator-(const fraction<T> &other) const
    {
        return {n * other.d - other.n * d, d * other.d};
    }
    constexpr fraction<T> operator*(const fraction<T> &other) const
    {
        return {n * other.n, d * other.d};
    }
    constexpr fraction<T> operator/(const fraction<T> &other) const
    {
        return {n * other.d, d * other.n};
    }
    constexpr fraction<T> operator+=(const fraction<T> &other)
    {
        return *this = {n * other.d + other.n * d,
                        d * other.d};
    }
    constexpr fraction<T> operator-=(const fraction<T> &other)
    {
        return *this = {n * other.d - other.n * d,
                        d * other.d};
    }
    constexpr fraction<T> operator*=(const fraction<T> &other)
    {
        return *this = {n * other.n, d * other.d};
    }
    constexpr fraction<T> operator/=(const fraction<T> &other)
    {
        return *this = {n * other.d, d * other.n};
    }
    constexpr bool operator<(const fraction<T> &other) const
    {
        return n * other.d < other.n * d;
    }
    constexpr bool operator<=(const fraction<T> &other) const
    {
        return !(other < *this);
    }
    constexpr bool operator>(const fraction<T> &other) const
    {
        return other < *this;
    }
    constexpr bool operator>=(const fraction<T> &other) const
    {
        return !(*this < other);
    }
    constexpr bool operator==(const fraction<T> &other) const
    {
        return n == other.n && d == other.d;
    }
    constexpr bool operator!=(const fraction<T> &other) const
    {
        return !(*this == other);
    }
};

template <typename T>
constexpr fraction<T> abs(const fraction<T> &f)
{
    return {f.n < 0 ? -f.n : f.n, f.d};
}

template <typename T>
std::istream &operator>>(std::istream &ins, fraction<T> &x)
{
    T n, d{T(1)};
    ins >> n;
    x = {n, d};
    return ins;
}

template <typename T>
std::ostream &operator<<(std::ostream &outs, const fraction<T> x)
{
    outs << "(" << x.n << "/" << x.d << ")";
    return outs;
}

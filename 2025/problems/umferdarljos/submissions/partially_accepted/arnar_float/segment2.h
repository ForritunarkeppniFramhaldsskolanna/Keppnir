#pragma once
#include "common.h"
#include "vec2.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <variant>

template <typename scalar_t = double_t>
struct segment2_t {
    vec2_t<scalar_t> p, q;

    constexpr bool operator==(const segment2_t& other) const {
        return p == other.p && q == other.q;
    }
    constexpr bool operator<(const segment2_t& other) const {
        return p == other.p ? q < other.q : p < other.p;
    }

    constexpr bool is_trivial() const {
        return p == q;
    }

    constexpr scalar_t length_squared() const {
        return (q - p).length_squared();
    }

    constexpr scalar_t length() const {
        return std::sqrt(length_squared());
    }

    constexpr scalar_t ccw(const vec2_t<scalar_t> a) const {
        return p.ccw(q, a);
    }

    constexpr bool contains(const vec2_t<scalar_t> point) const {
        return std::min(p.x, q.x) <= point.x && point.x <= std::max(p.x, q.x) &&
               std::min(p.y, q.y) <= point.y && point.y <= std::max(p.y, q.y) &&
               myabs((q.x - p.x) * (point.y - p.y) - (point.x - p.x) * (q.y - p.y)) <= EPS<scalar_t>;
    }

    using intersect_result_t = std::pair<intersection_t, std::variant<std::monostate, vec2_t<scalar_t>, segment2_t>>;
    constexpr intersect_result_t intersect(const segment2_t<scalar_t>& other) const {
        const auto r{ q - p };
        const auto s{ other.q - other.p };
        const auto c{ r * s };
        if (myabs(c) <= EPS<scalar_t>) {
            if (myabs((other.p - p) * r) > EPS<scalar_t>) {
                return {intersection_t::none, std::monostate{}};
            }
            auto numer1{ (other.p - p) % r };
            auto numer2{ numer1 + s % r };
            const auto denom{ r % r };
            if (numer2 < numer1) {
                std::swap(numer1, numer2);
            }
            const auto start{ std::max(scalar_t(0), numer1) };
            const auto end{ std::min(denom, numer2) };
            if (start == end) {
                return {intersection_t::one, p + r * (start / denom)};
            }
            if (start > end) {
                return {intersection_t::none, std::monostate{}};
            }
            return {intersection_t::infinite, segment2_t{p + r * (start / denom) , p + r * (end / denom)}};
        }

        const auto t_numer{ (other.p - p) * s };
        const auto t_denom{ r * s };
        const auto is_t_in_range{ std::min(scalar_t(0), t_denom) <= t_numer && t_numer <= std::max(scalar_t(0), t_denom) };

        const auto u_numer{ (p - other.p) * r };
        const auto u_denom{ s * r };
        const auto is_u_in_range{ std::min(scalar_t(0), u_denom) <= u_numer && u_numer <= std::max(scalar_t(0), u_denom) };

        if (is_t_in_range && is_u_in_range) {
            return {intersection_t::one, p + r * (t_numer / t_denom) };
        }
        return {intersection_t::none, std::monostate{}};
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& outs, const segment2_t<T>& s) {
    outs << "(" << s.p << " -- " << s.q << ")";
    return outs;
}

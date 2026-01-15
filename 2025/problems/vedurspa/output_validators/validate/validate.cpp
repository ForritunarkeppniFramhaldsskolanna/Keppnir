#include "validate.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <optional>
#include <string.h>
#include <vector>
using namespace std;

struct data_point_t {
    optional<double> temperature;
    optional<int> wind_direction;
    optional<double> wind_force;
    optional<int> humidity;
};

template <typename T, typename S>
optional<T> read_optional(S& in) {
    string s;
    if(!(in >> s)) {
        wrong_answer("Error reading optional value.\n");
    }
    if (s == "-") return nullopt;
    stringstream ss(s);
    T res;
    if (!(ss >> res)) {
        wrong_answer("Error reading optional value.\n");
    }
    return { res };
}

constexpr double threshold_multiplier{ 8 };
constexpr double min_temp{ -50.0 };
constexpr double max_temp{ 50.0 };
constexpr double max_temp_diff{ max_temp - min_temp };
constexpr double max_temp_err{ max_temp_diff  / threshold_multiplier };

constexpr double min_direction{ 0 };
constexpr double max_direction{ 360 };
constexpr double max_direction_diff{ 180.0 };
constexpr double max_direction_err{ max_direction_diff / threshold_multiplier };

constexpr double min_wind{ 0.0 };
constexpr double max_wind{ 80.0 };
constexpr double max_wind_diff{ max_wind - min_wind };
constexpr double max_wind_err{ max_wind_diff  / threshold_multiplier };

constexpr double min_humidity{ 0.0 };
constexpr double max_humidity{ 200.0 };
constexpr double max_humidity_diff{ max_humidity - min_humidity };
constexpr double max_humidity_err{ max_humidity_diff / threshold_multiplier };

int main(int argc, char **argv) {
    init_io(argc, argv);

    int n, m;
    judge_in >> n >> m;

    vector<data_point_t> expected_values(m);
    for (auto& dp : expected_values) {
        dp.temperature = read_optional<double>(judge_ans);
        dp.wind_direction = read_optional<int>(judge_ans);
        dp.wind_force = read_optional<double>(judge_ans);
        dp.humidity = read_optional<int>(judge_ans);
    }

    vector<data_point_t> actual_values(m);
    for (auto& dp : actual_values) {
        dp.temperature = read_optional<double>(author_out);
        dp.wind_direction = read_optional<int>(author_out);
        dp.wind_force = read_optional<double>(author_out);
        dp.humidity = read_optional<int>(author_out);
        if (dp.temperature.value_or(min_temp) < min_temp) wrong_answer("Solution output too low of a temperature.\n");
        if (dp.temperature.value_or(max_temp) > max_temp) wrong_answer("Solution output too high of a temperature.\n");
        if (dp.wind_direction.value_or(min_direction) < min_direction) wrong_answer("Solution output too low of a direction.\n");
        if (dp.wind_direction.value_or(max_direction) > max_direction) wrong_answer("Solution output too high direction.\n");
        if (dp.wind_force.value_or(min_wind) < min_wind) wrong_answer("Solution output too low of a wind force.\n");
        if (dp.wind_force.value_or(max_wind) > max_wind) wrong_answer("Solution output too high of a wind force.\n");
        if (dp.humidity.value_or(min_humidity) < min_humidity) wrong_answer("Solution output too low of a humidity.\n");
        if (dp.humidity.value_or(max_humidity) > max_humidity) wrong_answer("Solution output too high of a humidity.\n");
    }

    string s;
    author_out >> ws;
    if(author_out >> s) {
        wrong_answer("Trailing output.\n");
    }


    double accumulated_error{ 0.0 };
    int values_to_count{ 0 };
    for(int i = 0; i < m; ++i) {
        const auto& e{ expected_values[i] };
        const auto& a{ actual_values[i] };

        if (e.temperature.has_value()) {
            const auto diff{ a.temperature.has_value() ? abs(a.temperature.value() - e.temperature.value()) : max_temp_diff};
            accumulated_error += max(0.0, min(1.0, (diff * diff) / (max_temp_err)));
            values_to_count++;
        }

        if (e.wind_direction.has_value()) {
            const auto diff{ a.wind_direction.has_value() ? abs(a.wind_direction.value() - e.wind_direction.value()) : max_direction_err};
            const auto circular_diff{ min(diff, 360 - diff) };
            accumulated_error += max(0.0, min(1.0, (circular_diff * circular_diff) / (max_direction_err)));
            values_to_count++;
        }

        if (e.wind_force.has_value()) {
            const auto diff{ a.wind_force.has_value() ? abs(a.wind_force.value() - e.wind_force.value()) : max_wind_diff};
            accumulated_error += max(0.0, min(1.0, (diff * diff) / (max_wind_err)));
            values_to_count++;
        }

        if (e.humidity.has_value()) {
            const auto diff{ a.humidity.has_value() ? abs(a.humidity.value() - e.humidity.value()) : max_humidity_diff};
            accumulated_error += max(0.0, min(1.0, (diff * diff) / (max_humidity_err)));
            values_to_count++;
        }
    }
    const double score{ min(100.0, max(0.0, round(100.0 * (1 - accumulated_error / values_to_count)))) };
    if (score == 0) wrong_answer("Score too low\n");
    constexpr int num_tests{ 50 };
    accept_with_score(score / num_tests);

    return 0;
}

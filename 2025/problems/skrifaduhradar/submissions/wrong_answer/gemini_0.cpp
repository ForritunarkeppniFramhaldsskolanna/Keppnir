#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    int n;
    long long T;
    std::cin >> n >> T;
    std::vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> w[i];
    }
    std::sort(w.begin(), w.end());

    double low = 0.0;
    double high = 1e18; 

    for (int iter = 0; iter < 200; ++iter) {
        double mid = (low + high) / 2.0;
        long long penalty = 0;
        double current_time = 0.0;
        for (int i = 0; i < n; ++i) {
            double time_taken = (double)w[i] / mid;
            long long time_taken_minutes = (long long)time_taken;
            if (time_taken > time_taken_minutes) {
                time_taken_minutes++;
            }
            current_time += time_taken_minutes;
            penalty += (long long)current_time;

            if (penalty >= T) break;
        }

        if (penalty < T) {
            high = mid;
        } else {
            low = mid;
        }
    }

    std::cout << std::fixed << std::setprecision(10) << high << std::endl;

    return 0;
}

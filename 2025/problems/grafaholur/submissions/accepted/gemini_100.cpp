#include <iostream>
#include <iomanip>

int main() {
    int n, h, x, m, y;
    std::cin >> n >> h >> x >> m >> y;
    double rate_per_worker = (double)x / (n * h);
    double total_time = (double)y / (m * rate_per_worker);
    std::cout << std::fixed << std::setprecision(10) << total_time << std::endl;
    return 0;
}

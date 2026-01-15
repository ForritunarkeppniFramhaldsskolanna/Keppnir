#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<pair<long long, long long>> solutions;

    for (long long d = 1; d * (d + 1) / 2 <= n; ++d) {
        if ((2 * n) % d == 0) {
            long long numerator = 2 * n / d - (d - 1);
            if (numerator > 0 && numerator % 2 == 0) {
                long long f = numerator / 2;
                solutions.push_back({f, d});
            }
        }
    }

    sort(solutions.begin(), solutions.end());

    for (const auto& solution : solutions) {
        cout << solution.first << " " << solution.second << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const long long INF = 12 * 100000000;

int main() {
    vector<pair<long long, double>> steps(3);
    steps[0] = {409986, 31.45};
    steps[1] = {1151012, 37.95};
    steps[2] = {INF, 46.25};

    double l, s;
    cin >> l >> s;

    vector<long long> salary(12);
    for (int i = 0; i < 12; i++)
        cin >> salary[i];

    long long d = 59665;

    long long discount_left = 0, ans = 0;
    for (const auto amount : salary) {
        discount_left += d;

        long long pension = amount * l / 100.0;
        long long saving = amount * s / 100.0;
        long long tax_base = amount - pension - saving;

        double withholding = 0;
        long long left = tax_base, last_threshold = 0;
        for (auto step : steps) {
            long long a = step.first;
            double p = step.second;
            if (left <= 0)
                break;
            double in_bracket = min(left, a - last_threshold);
            withholding += in_bracket * p / 100.0;
            left -= in_bracket;
            last_threshold = a;
        }

        long long withholding_rounded = withholding;
        long long discount_to_use = min(discount_left, withholding_rounded);
        discount_left -= discount_to_use;
        long long after_tax = tax_base - withholding_rounded + discount_to_use;
        ans += after_tax;
    }
    cout << ans << endl;

    return 0;
}

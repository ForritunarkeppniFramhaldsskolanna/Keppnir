#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    size_t n, m, k;
    cin >> n >> m >> k;

    vector<size_t> popularities(n);
    size_t guests = 0;
    string _;
    bool low = true;
    bool all_same = true;
    size_t last = -1;
    for (auto& pop : popularities) {
        cin >> _ >> pop;
        guests += pop;
        if (pop > 999) low = false;
        if (last != -1 && pop != last) all_same = false;
        last = pop;
    }

    if (all_same) {
        const size_t buy_tickets{ guests * m };
        const size_t buy_cards{ popularities[0] * k };
        if (buy_tickets < buy_cards) {
            cout << 0 << " " << buy_tickets << endl;
        }
        else {
            cout << popularities[0] << " " << buy_cards << endl;
        }
    }
    else {
        vector<size_t> to_try;
        if (low) {
            to_try.resize(1000);
            iota(to_try.begin(), to_try.end(), 0);
        }
        else {
            to_try = popularities;
        }

        pair<size_t, size_t> mn{ guests * m, 0ULL };
        for (const auto cards : to_try) {
            size_t tickets{ 0 };
            for (const auto pop : popularities) {
                tickets += pop > cards ? pop - cards : 0;
            }
            const size_t cur{ tickets * m + cards * k };
            mn = min(mn, {cur, cards});
        }

        cout << mn.second << " " << mn.first << endl;
    }

    return 0;
}

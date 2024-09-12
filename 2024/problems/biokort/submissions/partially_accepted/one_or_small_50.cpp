#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t n, m, k;
    cin >> n >> m >> k;

    vector<size_t> popularities(n);
    size_t guests = 0;
    string _;
    bool all_same = true;
    size_t last = -1;
    for (auto& pop : popularities) {
        cin >> _ >> pop;
        guests += pop;
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
        pair<size_t, size_t> mn{ guests * m, 0ULL };
        for (size_t i{ 0ULL }; i < n; i++) {
            const size_t cards{ popularities[i] };
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

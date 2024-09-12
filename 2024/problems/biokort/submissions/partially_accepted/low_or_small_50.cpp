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
    for (auto& pop : popularities) {
        cin >> _ >> pop;
        guests += pop;
        if (pop > 999) low = false;
    }

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

    return 0;
}

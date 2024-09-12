#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t n, m, k;
    cin >> n >> m >> k;

    vector<size_t> popularities(n);
    string _;
    for (auto& pop : popularities) {
        cin >> _ >> pop;
    }

    sort(popularities.begin(), popularities.end());
    
    vector<size_t> cum_pop(n+1);
    for (size_t i = 0; i < n; i++) {
        cum_pop[i+1] = cum_pop[i] + popularities[i];
    }

    pair<size_t, size_t> mn{ m * cum_pop[n], 0ULL };
    for (size_t i{ 0ULL }; i < n; i++) {
        if (i + 1 < n && popularities[i] == popularities[i+1]) continue;
        const size_t cards{ popularities[i] };

        const size_t tickets{ cum_pop[n] - cum_pop[i + 1] - cards * (n - (i + 1)) };
        const size_t cur{ tickets * m + cards * k };
        mn = min(mn, {cur, cards});
    }

    cout << mn.second << " " << mn.first << endl;
        
    return 0;
}

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    size_t n, m, k;
    cin >> n >> m >> k;

    vector<size_t> popularities(n);
    size_t guests = 0;
    string _;
    for (auto& pop : popularities) {
        cin >> _ >> pop;
        guests += pop;
    }

    const size_t buy_tickets{ guests * m };
    const size_t buy_cards{ popularities[0] * k };
    if (buy_tickets <= buy_cards) {
        cout << 0 << " " << buy_tickets << endl;
    }
    else {
        cout << popularities[0] << " " << buy_cards << endl;
    }
        
    return 0;
}

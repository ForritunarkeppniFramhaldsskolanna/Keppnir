#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using box_t = vector<int>;

int main() {
    size_t n, m;
    cin >> n >> m;
    vector<box_t> boxes(n);
    for (size_t i = 0; i < n; i++) {
        size_t k;
        cin >> k;
        for (size_t j = 0; j < k; j++) {
            size_t x;
            cin >> x;
            boxes[i].push_back(x);
        }
    }

    for (size_t x = 1; x <= m; x++) {
        bool found{ any_of(boxes.begin(), boxes.end(), [x](const auto& box) {
            return find(box.begin(), box.end(), x) != box.end();
        }) };
        if (!found) {
            cout << "Neibb" << endl;
            return 0;
        }
    }
    cout << "Jebb" << endl;
    return 0;
}

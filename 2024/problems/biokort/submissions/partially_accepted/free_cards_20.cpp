
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

    size_t cards{ *max_element(popularities.begin(), popularities.end()) };
    cout << cards << " " << 0 << endl;
        
    return 0;
}

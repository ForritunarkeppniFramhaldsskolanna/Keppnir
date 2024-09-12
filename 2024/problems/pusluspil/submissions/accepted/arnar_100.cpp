#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using jigsaw_t = vector<bool>;

int main() {
    size_t n, m;
    cin >> n >> m;
    jigsaw_t jigsaw(m);
    for (size_t i = 0; i < n; i++) {
        size_t k;
        cin >> k;
        for (size_t j = 0; j < k; j++) {
            size_t x;
            cin >> x;
            jigsaw[x-1] = true;
        }
    }

    cout << (static_cast<size_t>(count(jigsaw.begin(), jigsaw.end(), true)) == m ? "Jebb" : "Neibb") << endl;
    return 0;
}

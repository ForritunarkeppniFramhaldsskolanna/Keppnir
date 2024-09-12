#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using jigsaw_t = vector<bool>;

int main() {
    size_t n, m;
    cin >> n >> m;
    jigsaw_t jigsaw(100000);
    for (size_t i = 0; i < n; i++) {
        size_t k;
        cin >> k;
        jigsaw_t box(100000);
        for (size_t j = 0; j < k; j++) {
            size_t x;
            cin >> x;
            box[x-1] = true;
        }
        for (size_t j = 0; j < 100000; j++) {
            jigsaw[j] = jigsaw[j] | box[j];
        }
    }

    cout << (static_cast<size_t>(count(jigsaw.begin(), jigsaw.end(), true)) == m ? "Jebb" : "Neibb") << endl;
    return 0;
}

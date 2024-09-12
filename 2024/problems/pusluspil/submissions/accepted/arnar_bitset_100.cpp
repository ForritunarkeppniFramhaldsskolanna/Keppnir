#include <bitset>
#include <iostream>

using namespace std;
using jigsaw_t = bitset<500000>;

int main() {
    size_t n, m;
    cin >> n >> m;
    jigsaw_t jigsaw{};
    for (size_t i = 0; i < n; i++) {
        size_t k;
        cin >> k;
        for (size_t j = 0; j < k; j++) {
            size_t x;
            cin >> x;
            jigsaw[x-1] = true;
        }
    }

    cout << (jigsaw.count() == m ? "Jebb" : "Neibb") << endl;
    return 0;
}

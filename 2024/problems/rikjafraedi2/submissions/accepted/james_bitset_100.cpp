#include <iostream>
#include <vector>
#include <sstream>
#include <bitset>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    vector<bitset<1024> > adj(n);
    for (int i = 0; i < n; ++i) {
        adj[i].set(i);
    }

    for (int i = 0; i < q; ++i) {
        int o, x, y;
        cin >> o >> x >> y;

        if (o == 0) {
            adj[x - 1] |= adj[y - 1];
            for (int j = 0; j < n; ++j) {
                if (j == x - 1) continue;
                if (adj[j].test(x - 1)) {
                    adj[j] |= adj[x - 1];
                }
            }
        } else if (o == 1) {
            if (adj[x - 1].test(y - 1)) {
                cout << "Jebb\n";
            } else {
                cout << "Neibb\n";
            }
        }
    }

    return 0;
}

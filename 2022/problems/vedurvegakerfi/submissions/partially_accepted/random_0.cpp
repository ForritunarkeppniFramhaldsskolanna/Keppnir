#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
    srand(time(NULL));
    int n, m, q, x = 0, aj, bj, hj; cin >> n >> m >> q;
    for(int i = 0; i < m; ++i)
        cin >> x >> x >> x;
    for(int i = 0; i < q; ++i) {
        cin >> aj >> bj >> hj;
        if(rand() % 2 == 0) cout << "Jebb\n";
        else cout << "Neibb\n";
    }
}

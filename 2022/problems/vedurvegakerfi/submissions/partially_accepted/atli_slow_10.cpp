#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
    int n, m, q, x = 0, aj, bj, hj; cin >> n >> m >> q;
    vi stp(m); 
    for(int i = 0; i < m; ++i)
        cin >> stp[i] >> stp[i] >> stp[i];
    for(int i = 0; i < q; ++i) {
        cin >> aj >> bj >> hj;
        aj ^= x; bj ^= x; hj ^= x;
        aj--; bj--;
        int up = aj, dn = aj;
        while(up != bj) {
            if(stp[up] < hj) break;
            up = (up + 1) % n;
        }
        while(dn != bj) {
            if(stp[(dn + n - 1) % n] < hj) break;
            dn = (dn + n - 1) % n;
        }
        if(up == bj || dn == bj) {
            cout << "Jebb\n";
            x++;
        } else {
            cout << "Neibb\n";
        }
    }
}

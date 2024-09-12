#include<bits/stdc++.h>
using namespace std;

const int n = 300;

int main() {
    ios_base::sync_with_stdio(false);
    int K, q, ans; cin >> K >> q;
    int res[n];
    if(K == 2) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j)
                cout << (i == j ? 1 : 0) << ' ';
            cout << '\n' << flush;
            cin >> res[i];
        }
    } else if(K == 4) {
        for(int i = 0; i < n / 2; ++i) {
            for(int j = 0; j < n; ++j) {
                if(j == 2 * i) cout << 1 << ' ';
                else if(j == 2 * i + 1) cout << 100 << ' ';
                else cout << 0 << ' ';
            }
            cout << '\n' << flush;
            cin >> ans;
            res[2 * i] = ans % 100;
            res[2 * i + 1] = ans / 100;
        }
    } else {
        for(int i = 0; i < n / 3; ++i) {
            for(int j = 0; j < n; ++j) {
                if(j == 3 * i) cout << 1 << ' ';
                else if(j == 3 * i + 1) cout << 100 << ' ';
                else cout << 0 << ' ';
            }
            cout << '\n' << flush;
            cin >> ans;
            res[3 * i] = ans % 100;
            res[3 * i + 1] = ans / 100;
            for(int j = 0; j < n; ++j) {
                if(j == 3 * i + 1) cout << 10 << ' ';
                else if(j == 3 * i + 2) cout << 1 << ' ';
                else cout << 0 << ' ';
            }
            cout << '\n' << flush;
            cin >> ans;
            ans -= res[3 * i + 1] * 10;
            res[3 * i + 2] = ans % 100;
            res[3 * i + 1] += 10 * (ans / 100);
        }
    }
    for(int i = 0; i < n; ++i)
        cout << res[i] << ' ';
    cout << '\n' << flush;
}

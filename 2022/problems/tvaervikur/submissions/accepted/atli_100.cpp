#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, B, s = 0, mx = -1, mxind = -1, x;
    cin >> n >> B;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        x = (x + B - 1) / B;
        s += x;
        if(x > mx) mx = x, mxind = i;
    }
    if(2 * mx > s) {
        for(int i = 0; i < n; ++i) cout << (i == mxind ? "1 " : "2 ");
        cout << '\n';
    } else {
        for(int i = 0; i < n; ++i) cout << "1 ";
        cout << '\n';
    }
}

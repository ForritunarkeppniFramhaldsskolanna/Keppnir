#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

int main() {
    ll n, B;
    cin >> n >> B;
    vl xs(n);
    for(int i = 0; i < n; ++i) {
        cin >> xs[i];
        xs[i] = (xs[i] + B - 1) / B;
    }
    for(int i = 0; i < n; ++i) {
        ll sm = 0, mx = -1;
        for(int j = 0; j < n; ++j) {
            if(i == j) continue;
            sm += xs[j];
            mx = max(mx, xs[j]);
        }
        sm -= mx;
        if(sm + xs[i] >= mx) cout << "1 ";
        else cout << "2 ";
    }
    cout << '\n';
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m, ka, kb;
    cin >> n >> m >> ka >> kb;
    vector<ll> ks = { ka };
    for(int i = 0; i < m; ++i) {
        ll ki; cin >> ki;
        ks.push_back(ki);
    }
    ks.push_back(kb);
    reverse(ks.begin(), ks.end());
    for(int i = 0; i < ks.size(); ++i) {
        ks[i] = min(n, ks[i]);
    }
    ll ans = 0;
    for(ll k : ks) {
        if(k == n) continue;
        if(ans / k == n / k) ans += (n % k) - 1 - 2 * (ans % k);
        else ans += k - 1 - 2 * (ans % k);
        ans = n - 1 - ans;
    }
    cout << ans + 1 << '\n';
}

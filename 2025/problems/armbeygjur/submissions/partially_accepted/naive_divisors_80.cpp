#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> l2;

vector<ll> divisors(ll x) {
    vector<ll> res;
    for(ll y = 1; y * y <= x; ++y) {
        if(x % y == 0) {
            res.push_back(y);
            if(y * y != x)
                res.push_back(x / y);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x; cin >> x;
    vector<l2> outp;
    for(ll y : divisors(x)) {
        if(y % 2 == 0) continue;
        ll f = x / y - (y - 1) / 2;
        if(f < 1) y -= -2 * f + 1, f = -f + 1;
        outp.emplace_back(f, y);
    }
    sort(outp.begin(), outp.end());
    for(auto p : outp)
        cout << p.first << ' ' << p.second << '\n';
}

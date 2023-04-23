#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> l4;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

l4 frac_max(l4 a, l4 b) {
    if(a.first * b.second < b.first * a.second) return b;
    if(a.first * b.second > b.first * a.second) return a;
    return a.first < b.first ? a : b;
}

int main() {
    ios_base::sync_with_stdio(false);
    l4 mx(0, 0);
    ll gm = 0, wn = 0;
    string s;
    cin >> s >> s;
    for(auto it = s.rbegin(); it != s.rend(); ++it) {
        if(mx == l4(0, 0) && *it == 'G') mx = l4(1, 1);
        if(mx == l4(0, 0) && *it == 'A') mx = l4(0, 1);
        if(*it != 'D') gm++;
        if(*it == 'G') wn++;
        mx = frac_max(mx, l4(wn, gm));
    }
    cout << mx.first << '-' << mx.second - mx.first << '\n';
}

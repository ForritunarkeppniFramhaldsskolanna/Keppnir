#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

ll egcd(ll a, ll b, ll& x, ll& y) {
  if(b == 0) { x = 1; y = 0; return a; }
  ll d = egcd(b, a % b, x, y);
  x -= a / b * y; swap(x, y); return d; }

ll mod_inv(ll a, ll m) {
  ll x, y, d = egcd(a, m, x, y);
  return d == 1 ? (x%m+m)%m : -1; }

int main() {
    int n, m, s, t, a, b, x;
    cin >> n >> m >> s >> t;
    if(s > t) swap(s, t);
    ll res = 0; bool set = false;
    for(int i = 0; i < m; ++i) {
        cin >> a >> b >> x;
        if(a > b) swap(a, b);
        if(a == s && b == t) {
            if(!set) {
                res = x;
                set = true;
            } else {
                res = mod_inv(mod_inv(res, mod) + mod_inv(x, mod), mod);
            }
        }
    }
    cout << res << '\n';
}

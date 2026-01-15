#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
typedef __int128 bl;
#define rep(i,a,b) for(auto i = (a); i < (b); ++i)

ll int_pow(ll b, ll e) {
  ll res = 1;
  while(e--) res *= b;
  return res; }

ll mod_pow(bl b, ll e, ll m) {
  bl res = 1; while(e) {
    if(e & 1) res = (res*b%m+m)%m;
    b *= b; b %= m; e >>= 1; }
  return res; }

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll rho(ll n) {
    for(ll s : { 2, 3, 5, 7, 11, 13, 1031 }) {
        bl x = s, y = x, d = 1;
        while(d == 1) {
            x = (x * x + 1) % n;
            y = (y * y + 1) % n;
            y = (y * y + 1) % n;
            bl xy{ x - y };
            d = gcd(xy < 0 ? -xy : xy, n);
        }
        if(d == n) continue;
        return d;
    }
    return -1;
}

const ll mod = 1e9 + 7;

bool is_probable_prime(ll n, int k) {
  if (~n & 1) return n == 2;
  if (n <= 3) return n == 3;
  int s = 0; ll d = n - 1;
  while (~d & 1) d >>= 1, s++;
  while (k--) {
    bl a = n - 3;
    a *= rand();
    a /= RAND_MAX;
    a += 2;
    bl x = mod_pow(a % n, d, n);
    if (x == 1 || x == n - 1) continue;
    bool ok = false;
    rep(i,0,s-1) {
      x = x * x % n;
      if (x == 1) return false;
      if (x == n - 1) { ok = true; break; }
    }
    if (!ok) return false;
  } return true; }

int eratos[100000];

void calceratos() {
    for(int i = 0; i < 100000; ++i) eratos[i] = i;
    for(ll i = 2; i * i < 100000; ++i) {
        if(eratos[i] == i) {
            for(ll j = i * i; j < 100000; j += i) {
                eratos[j] = i;
            }
        }
    }
}

map<ll,int> factors(ll x) {
    map<ll,int> cnt;
    for(int i = 2; i < 100000; ++i) {
        if(eratos[i] != i) continue;
        while(x % i == 0) {
            x /= i;
            if(!cnt.count(i)) cnt[i] = 0;
            cnt[i]++;
        }
    }
    vector<ll> st;
    st.push_back(x);
    while(st.size() > 0) {
        ll y = st.back();
        st.pop_back();
        if(y == 1) continue;
        if(cnt.count(y) || is_probable_prime(y, 5)) {
            if(!cnt.count(y)) cnt[y] = 0;
            cnt[y]++;
        } else {
            ll d = rho(y);
            st.push_back(d);
            st.push_back(y / d);
        }
    }
    return cnt;
}

void divgen(vector<pair<ll,int>> &facs, vector<ll> &res, ll x, int i) {
    if(i == (int) facs.size()) {
        res.push_back(x);
        return;
    }
    for(int j = 0; j <= facs[i].second; ++j) {
        divgen(facs, res, x * int_pow(facs[i].first, j), i + 1);
    }
}

vector<ll> odd_divisors(ll x) {
    map<ll,int> fac = factors(x);
    vector<pair<ll,int>> facvec; vector<ll> res;
    for(auto p : fac) 
        if(p.first != 2)
            facvec.push_back(p);
    divgen(facvec, res, 1, 0);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    calceratos();
    ll x; cin >> x;
    vector<pair<ll,ll>> outp;
    for(ll y : odd_divisors(x)) {
        ll f = x / y - (y - 1) / 2;
        if(f < 1) y -= -2 * f + 1, f = -f + 1;
        outp.emplace_back(f, y);
    }
    sort(outp.begin(), outp.end());
    for(auto p : outp)
        cout << p.first << ' ' << p.second << '\n';
}

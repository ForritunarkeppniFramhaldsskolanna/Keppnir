#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
typedef __int128 ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
template <class T> int size(const T &x) { return x.size(); }
const int INF = 2147483647;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

ll mod_pow(ll b, ll e, ll m) {
    ll res = 1;
    while (e) {
        if (e & 1) {
            res = res * b % m;
        }
        b = b * b % m;
        e >>= 1;
    }
    return res;
}

bool is_probable_prime(ll n, int k) {
    if (~n & 1) return n == 2;
    if (n <= 3) return n == 3;
    int s = 0; ll d = n - 1;
    while (~d & 1) d >>= 1, s++;
    while (k--) {
        ll a = (n - 3) * rand() / RAND_MAX + 2;
        ll x = mod_pow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool ok = false;
        rep(i,0,s-1) {
            x = (x * x) % n;
            if (x == 1) return false;
            if (x == n - 1) { ok = true; break; }
        }
        if (!ok) return false;
    }
    return true;
}

bool is_prime(ll n) {
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(1337);
    long long n;
    cin >> n;
    vector<ll> ps;
    for (ll i = 2; ; i++) {
        if (is_prime(i)) {
            ps.push_back(i);
            iter(it,ps) {
                ll t = n - i - *it;
                if (t >= 2 && is_probable_prime(t, 20)) {
                    cout << (long long)*it << " " << (long long)i << " " << (long long)t << endl;
                    return 0;
                }
            }
        }
    }
    return 1;
}


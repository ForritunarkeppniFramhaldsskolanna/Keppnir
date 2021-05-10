#include <bits/stdc++.h>
using namespace std;
//template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

__int128 smod(__int128 a, __int128 b) {
    return (a % b + b) % b;
}

template <class T>
T mod_pow(T b, T e, T m) {
  T res = T(1);
  while (e) {
    if (e & T(1)) res = smod(res * b, m);
    b = smod(b * b, m), e >>= T(1); }
  return res; }

bool is_probable_prime(__int128 n, int k) {
  if (~n & 1) return n == 2;
  if (n <= 3) return n == 3;
  int s = 0; __int128 d = n - 1;
  while (~d & 1) d >>= 1, s++;
  while (k--) {
    __int128 a = (n - 3) * rand() / RAND_MAX + 2;
    __int128 x = mod_pow(a, d, n);
    if (x == 1 || x == n - 1) continue;
    bool ok = false;
    rep(i,0,s-1) {
      x = (x * x) % n;
      if (x == 1) return false;
      if (x == n - 1) { ok = true; break; }
    }
    if (!ok) return false;
  } return true; }

int main() {
    ll a, b;
    cin >> a >> b;
    ll cnt = 0;
    for (ll i = a; i <= b; i++) {
        if (is_probable_prime(i, 15)) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}


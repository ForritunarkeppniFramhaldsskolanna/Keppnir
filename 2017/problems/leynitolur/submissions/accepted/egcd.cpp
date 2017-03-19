#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef __int128 ll;
const int INF = 2147483647;

ll egcd(ll a, ll b, ll& x, ll& y) {
  if (b == 0) {
      x = 1;
      y = 0;
      return a;
  }
  ll d = egcd(b, a % b, x, y);
  x -= a / b * y;
  swap(x, y);
  return d;
}

int main() {
    ll mod = 1;
    rep(i,0,64) mod <<= 1;

    unsigned long long n;
    while (cin >> n) {
        ll a = 230309227;
        unsigned long long b = 68431307;
        ll x, y;
        egcd(a, mod, x, y);
        cout << (n - b) * (unsigned long long)x << endl;
    }

    return 0;
}


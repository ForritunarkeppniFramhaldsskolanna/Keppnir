#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdint>

using namespace std;

using lli = long long int;

using u64 = uint64_t;
#ifdef __GNUC__
using u128 = __uint128_t;
#else
using u128 = uint64_t;
#endif

// Brent algorithm to find prime divisors
// alternative using int128:
lli mult(u64 a, u64 b, u64 mod) {
  return (u128)a * b % mod;
}

//lli mult(lli a, lli b, lli mod) {
//  lli result = 0;
//  while (b) {
//    if (b & 1)
//      result = (result + a) % mod;
//    a = (a + a) % mod;
//    b >>= 1;
//  }
//  return result;
//}

lli f(lli x, lli c, lli mod) {
  return (mult(x, x, mod) + c) % mod;
}

lli gcd(lli a, lli b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

// Brent algorithm, sped up
lli brent(lli n, lli x0 = 2, lli c = 1) {
  lli x = x0;
  lli g = 1;
  lli q = 1;
  lli xs, y;

  int m = 128;
  int l = 1;
  while (g == 1) {
    y = x;
    for (int i = 1; i < l; i++)
      x = f(x, c, n);
    int k = 0;
    while (k < l && g == 1) {
      xs = x;
      for (int i = 0; i < m && i < l - k; i++) {
        x = f(x, c, n);
        q = mult(q, abs(y - x), n);
      }
      g = gcd(q, n);
      k += m;
    }
    l *= 2;
  }
  if (g == n) {
    do {
      xs = f(xs, c, n);
      g = gcd(abs(xs - y), n);
    } while (g == 1);
  }
  return g;
}

u64 binpower(u64 base, u64 e, u64 mod) {
  u64 result = 1;
  base %= mod;
  while (e) {
    if (e & 1)
      result = (u128)result * base % mod;
    base = (u128)base * base % mod;
    e >>= 1;
  }
  return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
  auto x = binpower(a, d, n);
  if (x == 1 || x == n - 1)
    return false;
  for (int r = 1; r < s; r++) {
    x = (u128)x * x % n;
    if (x == n - 1)
      return false;
  }
  return true;
};

// returns true if n is prime, else returns false
bool MillerRabin(u64 n) {
  if (n < 2) return false;

  int r = 0;
  u64 d = n - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    r++;
  }

  for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23}) {
    if (n == a) return true;
    if (check_composite(n, a, d, r)) return false;
  }
  return true;
}

const int maxn = 1e5;
u64 divisor[maxn + 1];

bool is_prime(u64 n) {
  if (n <= maxn) return divisor[n] == n;
  else return MillerRabin(n);
}

// n >= 2
u64 get_some_prime(u64 n) {
  if (n <= maxn) return divisor[n];
  if (!(n & 1)) return 2;
  if (is_prime(n)) return n;
  u64 g = brent(n);
  while (!is_prime(g)) {
    auto newg = brent(g);
    if (newg == g) {
      newg = brent(g, 2, rand() % (g - 1) + 1);
    }
    g = newg;
  }
  return g;
}

lli pow[30][65];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = 2; i <= maxn; ++i) {
    if (!divisor[i]) {
      divisor[i] = i;
      if (i * 1ll * i <= maxn) {
        for (int j = i * i; j <= maxn; j += i) {
          divisor[j] = i;
        }
      }
    }
  }

  u64 n; cin >> n;
  u64 n2 = n;
  unordered_map<u64, int> f;
  f[2] = 1;
  while (n2 > 1) {
    auto p = get_some_prime(n2);
    while (n2 % p == 0) {
      f[p]++;
      n2 /= p;
    }
  }
  vector<pair<u64, int>> f2;
  for (auto& x : f) f2.push_back({x.first, x.second});
  int m = 1;
  vector<int> pref;
  int i2 = 0;
  for (auto& x : f2) {
    pref.push_back(m);
    m *= (x.second + 1);
    pow[i2][0] = 1;
    for (int i = 1; i <= x.second; ++i) pow[i2][i] = pow[i2][i - 1] * x.first;
    i2++;
  }
  vector<lli> divisors;
  for (int i = 0; i < m; ++i) {
    lli k = 1;
    for (int j = 0; j < f2.size(); ++j) {
      k *= pow[j][(i / pref[j]) % (f2[j].second + 1)];
    }
    if (k < n * 2 / k) divisors.push_back(k);
  }
  sort(divisors.begin(), divisors.end(), greater<lli>());
  for (auto x : divisors) {
    auto y = n * 2 / x;
    if ((y - x) & 1) {
      cout << ((y - x + 1) >> 1) << ' ' << x << endl;
    }
  }
  return 0;
}

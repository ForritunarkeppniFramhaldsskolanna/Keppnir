#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

struct hash_ii {
  size_t operator()(const ii& p) const
  {
    return hash<ll>()(((ll)p.first)^ (((ll)p.second) << 32));
  }
};

unordered_map<ii, double, hash_ii> mem;

double dp(int n, int m) {
  if (n == 0 || m == 0) return m;
  ii p = make_pair(n, m);
  if (mem.find(p) != mem.end()) return mem[p];

  double ans = (dp(n-1, m-1) + dp(n-1, m)) / 2.0;
  return mem[p] = ans;
}

int main() {
  int n,m;
  cin >> n >> m;
  cout << setprecision(10) << dp(n,m) << endl;
  return 0;
}

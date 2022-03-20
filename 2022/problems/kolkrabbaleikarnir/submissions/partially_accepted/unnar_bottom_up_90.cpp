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

int main() {
  int n,m;
  cin >> n >> m;
  double dp[1001][1001];

  rep(i, 0, n+1) {
    rep(j, 0, m+1) {
      if (i == 0 || j == 0) dp[i][j] = j;
      else dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) / 2.0;
    }
  }
  cout << setprecision(10) << dp[n][m] << endl;
  return 0;
}

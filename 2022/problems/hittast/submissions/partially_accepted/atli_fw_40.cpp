#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define rep(i,a,b) for(auto i = (a); i < (b); ++i)

vvi floydwarshall(vvii& g) {
  int n = g.size();
  vvi dp(n, vi(n, INT_MAX / 4));
  rep(i, 0, n) dp[i][i] = 0;
  rep(i, 0, n) for(ii x : g[i])
    dp[i][x.second] = min( x.first, dp[i][x.second]);
  rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) {
    if(dp[i][k] == INT_MAX / 4 ||
      dp[k][j] == INT_MAX / 4) continue;
    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); }
  rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) {
    if(dp[i][k] == INT_MAX / 4 || dp[k][j] == INT_MAX / 4 ||
      dp[i][j] == INT_MAX / 4) continue;
    if(dp[i][k] + dp[k][j] < dp[i][j]) dp[i][j] = -(INT_MAX / 4); }
  return dp; }

int main() {
    int n, m, u, v, a, b;
    cin >> n >> m;
    vi g(n);
    for(int i = 0; i < n; ++i) cin >> g[i];
    vvii ga(n, vii()), gb(n, vii());
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> a >> b;
        u--; v--;
        ga[u].push_back(ii(a, v));
        ga[v].push_back(ii(a, u));
        gb[u].push_back(ii(b, v));
        gb[v].push_back(ii(b, u));
    }
    vvi da = floydwarshall(ga);
    vvi db = floydwarshall(gb);
    int bst = INT_MAX;
    for(int i = 0; i < n; ++i) {
        bst = min(bst, da[0][i] + db[i][n - 1] + g[i]);
    }
    cout << bst << '\n';
}

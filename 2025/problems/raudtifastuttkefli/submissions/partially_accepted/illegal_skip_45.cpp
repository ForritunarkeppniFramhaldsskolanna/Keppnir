#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

int l[1000];
int d[1000];
long long int dp[1001][100000];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k; cin >> n >> k;
  int maxt = 0;
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> d[i];
    maxt += l[i];
  }
  int t; cin >> t;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (l[i] <= k) {
      for (int j = 0; j <= maxt; j++) {
        if (j < l[i])
          dp[i + 1][j] = 0;
        else
          dp[i + 1][j] = dp[i][j - l[i]] + d[i];
        if (j) dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - 1]);
      }
    } else {
      for (int j = 0; j <= maxt; j++) {
        if (j < k)
          dp[i + 1][j] = 0;
        else if (j < l[i])
          dp[i + 1][j] = dp[i][j - k];
        else
          dp[i + 1][j] = max(dp[i][j - k], dp[i][j - l[i]] + d[i]);
        if (j) dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - 1]);
      }
    }
    ans = max(ans, dp[i + 1][min(maxt, t)]);
  }
  cout << ans;

  return 0;
}

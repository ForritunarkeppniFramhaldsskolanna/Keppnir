#include <iostream>
#include <cstring>

using namespace std;

int dp[1001][1001][2];
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n; n /= 5;
  memset(dp, 127, sizeof(dp));
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; ++i) dp[i][0][0] = dp[0][i][0] = i;
  int cnt = 4 * n + 1;
  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= n; ++y) {
      for (int k = 0; k <= 1; ++k) dp[x][y][k] = min(dp[x - 1][y][k], dp[x][y - 1][k]) + 1;
      dp[x][y][1] = min(dp[x][y][1], dp[x - 1][y - 1][0] + 1);
      dp[x][y][0] = min(dp[x][y][0], dp[x - 1][y - 1][1] + 2);
      cnt += 4 * (min(dp[x][y][0], dp[x][y][1]) <= n);
    }
  }
  cout << cnt;
  return 0;
}

#include <queue>
#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<char, int, int>> ops;
int dist[100000000];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  memset(dist, 127, sizeof(dist));

  int n, x0; cin >> n >> x0;
  for (int i = 0; i < n; ++i) {
    char c; int y, cnt; cin >> c >> y >> cnt;
    ops.emplace_back(c, y, cnt);
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({0, x0});
  dist[x0] = 0;
  while (!q.empty()) {
    auto [d, x] = q.top();
    if (x == 0) break;
    if (d >= dist[0]) break;
    if (d > dist[x]) continue;
    q.pop();
    vector<pair<int, int>> nexts;
    for (int i = 0; i < n; ++i) {
      auto& [c, y, cnt] = ops[i];
      if (c == '/') {
        for (int j = x * y; j < (x + 1) * y && j < 1e8; ++j) nexts.push_back({d + cnt, j});
      } else if (c == '*') {
        if (y && x % y == 0) nexts.push_back({d + cnt, x / y});
      } else if (c == '-') {
        if (x + y < 1e8) nexts.push_back({d + cnt, x + y});
      } else {
        if (x >= y) nexts.push_back({d + cnt, x - y});
      }
    }
    for (auto& nxt : nexts) {
      if (dist[nxt.second] > nxt.first) {
        dist[nxt.second] = nxt.first;
        q.push(nxt);
      }
    }
  }

  if (dist[0] > 1e9)
    cout << "Engin leid!";
  else
    cout << dist[0];

  return 0;
}

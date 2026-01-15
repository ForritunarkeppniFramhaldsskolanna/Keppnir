#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

const int block_size = 1024;
char op[5];
int y[5];
int c[5];
int dist[100000000];
queue<int> q[block_size];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  memset(dist, 127, sizeof(dist));

  int n, x0; cin >> n >> x0;
  for (int i = 0; i < n; ++i) {
    cin >> op[i] >> y[i] >> c[i];
  }
  q[0].push(0);
  dist[0] = 0;
  for (int d = 0; d < 3 * 1e8; ++d) {
    int d_ = d % block_size;
    while (!q[d_].empty()) {
      int x = q[d_].front();
      q[d_].pop();
      if (x == x0) break;
      if (dist[x] < d) continue;
      for (int i = 0; i < n; ++i) {
        int nxt = x;
        if (op[i] == '/') {
          nxt /= y[i];
        } else if (op[i] == '*') {
          if (x * y[i] < 1e8) nxt = x * y[i];
        } else if (op[i] == '-') {
          if (x >= y[i]) nxt = x - y[i];
        } else {
          if (x + y[i] < 1e8) nxt = x + y[i];
        }
        if (dist[nxt] > d + c[i]) {
          dist[nxt] = d + c[i];
          q[(d + c[i]) % block_size].push(nxt);
        }
      }
    }
    if (dist[x0] == d) break;
  }

  if (dist[x0] > 1e9)
    cout << "Engin leid!";
  else
    cout << dist[x0];

  return 0;
}

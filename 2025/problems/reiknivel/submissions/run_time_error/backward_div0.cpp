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
  q[0].push(x0);
  dist[x0] = 0;
  for (int d = 0; d < 3 * 1e8; ++d) {
    int d_ = d % block_size;
    while (!q[d_].empty()) {
      int x = q[d_].front();
      q[d_].pop();
      if (x == 0) break;
      if (dist[x] < d) continue;
      for (int i = 0; i < n; ++i) {
        int nxt = x;
        if (op[i] == '/') {
          if (x * y[i] < 1e8) nxt = x * y[i];
        } else if (op[i] == '*') {
          if (x % y[i] == 0) nxt = x / y[i];
        } else if (op[i] == '+') {
          if (x >= y[i]) nxt = x - y[i];
        } else {
          if (x + y[i] < 1e8) nxt = x + y[i];
        }
        for (int j = 0; j < ((op[i] == '/') ? y[i] : 1); ++j) {
          if (dist[nxt] > d + c[i]) {
            dist[nxt] = d + c[i];
            q[(d + c[i]) % block_size].push(nxt);
          }
          nxt++; if (nxt >= 1e8) break;
        }
      }
    }
    if (dist[0] == d) break;
  }

  if (dist[0] > 1e9)
    cout << "Engin leid!";
  else
    cout << dist[0];

  return 0;
}

#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n; n /= 5;
  int cnt = 0;
  for (int x = -n; x <= n; ++x) {
    for (int y = -n; y <= n; ++y) {
      cnt += min(abs(x), abs(y)) / 2 + max(abs(x), abs(y)) <= n;
    }
  }
  cout << cnt;
  return 0;
}

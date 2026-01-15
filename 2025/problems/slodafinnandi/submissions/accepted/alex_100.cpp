#include <iostream>

using namespace std;

using lli = long long int;

void cout128(__int128 x) {
  if (x > 9) cout128(x / 10);
  cout << char(int(x % 10) + '0');
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  lli n_; cin >> n_; n_ /= 5;
  __int128 n(n_);
  __int128 k((n + 1) / 3 - 1);
  cout128(n * n * 4 - (n * 2 - k * 3 - 4) * (k + 1) * 4 + (n * 2 + 1) / 3 * 4 + 1);

  return 0;
}

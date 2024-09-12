#include "bits/stdc++.h"

using namespace std;

const long long int m = 1000000007;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  long long n; cin >> n;
  long long res = 1ll;
  for (int i = 0; i < 20; ++i) res = (res * (n - i)) % m;
  for (int i = 0; i < 3; ++i) res = (res + (res & 1) * m) >> 1;
  cout << res;

  return 0;
}

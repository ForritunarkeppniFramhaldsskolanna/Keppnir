#include "bits/stdc++.h"

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int a, b, c; cin >> a >> b >> c;
  float mid = -b / (a * 2.0);
  float mid_value = a * mid * mid + b * mid + c;
  if (mid_value < 0)
    cout << 2;
  else if (mid_value == 0)
    cout << 1;
  else
    cout << 0;

  return 0;
}

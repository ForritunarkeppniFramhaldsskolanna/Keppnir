#include "bits/stdc++.h"

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int a, b, c; cin >> a >> b >> c;
  int d2 = b * b - a * c * 4;
  if (d2 < 0) cout << 0; else {
    float x1 = (-b + sqrt(d2)) / (a * 2);
    float x2 = (-b - sqrt(d2)) / (a * 2);
    if (x1 == x2)
      cout << 1;
    else
      cout << 2;
  }

  return 0;
}

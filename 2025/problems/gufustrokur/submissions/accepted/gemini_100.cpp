#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int diff1 = abs(a - b);
  int diff2 = 360 - diff1;

  cout << min(diff1, diff2) << endl;

  return 0;
}

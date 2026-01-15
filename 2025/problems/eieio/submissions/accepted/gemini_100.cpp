#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  // Let s be the number of sheep and p be the number of people.
  // We have two equations:
  // 1) s + p = n
  // 2) 4s + 2p = m

  // From equation (1), we can express p as p = n - s.
  // Substitute this into equation (2):
  // 4s + 2(n - s) = m
  // 4s + 2n - 2s = m
  // 2s = m - 2n
  // s = (m - 2n) / 2

  if ((m - 2 * n) % 2 != 0 || m < 2 * n) {
    cout << "Rong talning" << endl;
  } else {
    int s = (m - 2 * n) / 2;
    if (s >= 0 && s <= n)
      cout << s << endl;
    else
        cout << "Rong talning" << endl;
  }
  

  return 0;
}

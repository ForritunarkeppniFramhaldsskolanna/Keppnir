#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  if (n <= m) {
    if (n == m) {
      cout << "Dufur passa fullkomlega" << endl;
    } else {
      cout << "Dufur passa" << endl;
    }
  } else {
    cout << "Dufur passa ekki" << endl;
  }

  return 0;
}

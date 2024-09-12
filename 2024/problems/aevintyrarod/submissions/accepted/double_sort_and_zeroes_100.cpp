#include "bits/stdc++.h"

using namespace std;

int order[100000];
string name[100000];
int a[100000];
int b[100000];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, x; cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    order[i] = i;
    cin >> name[i];
    cin >> a[i];
    cin >> b[i];
  }
  sort(order, order + n, [&](int fd, int sd) {
    if (b[fd] == 0 && b[sd] == 0) return a[fd] == a[sd] ? fd < sd : a[fd] < a[sd];
    if (b[fd] == 0) return false; // 0/0 or inf vs non-inf
    if (b[sd] == 0) return true; // non-inf vs inf or 0/0
    double x1 = double(a[fd]) / b[fd];
    double x2 = double(a[sd]) / b[sd];
    if (x1 == x2) return fd < sd; else
    return x1 < x2;
  });

  for (int i = 0; i < n; ++i) {
    cout << name[order[i]] << endl;
  }

  return 0;
}

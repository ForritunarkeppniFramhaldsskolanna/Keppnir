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
    int x1 = (a[fd]) * b[sd];
    int x2 = (a[sd]) * b[fd];
    if (x1 == x2) return fd < sd; else
    return x1 < x2;
  });

  // swap adjacent identical gains randomly
  for (int i = 0; i < n - 1; ++i) {
    if (a[order[i]] * b[order[i + 1]] == a[order[i + 1]] * b[order[i]] && (rand() & 1)) swap(order[i], order[i + 1]);
  }

  for (int i = 0; i < n; ++i) {
    cout << name[order[i]] << endl;
  }

  return 0;
}

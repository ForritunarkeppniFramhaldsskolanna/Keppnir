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

  vector<string> zeroes;
  int n, x; cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    order[i] = i;
    cin >> name[i];
    cin >> a[i];
    cin >> b[i];
    if (a[i] == 0 && b[i] == 0) { // dirty hack to remove zeroes
      zeroes.push_back(name[i]);
      i--;
      n--;
    }
  }
  sort(order, order + n, [&](int fd, int sd) {
    int x1 = (a[fd]) * b[sd];
    int x2 = (a[sd]) * b[fd];
    if (x1 == x2) return fd < sd; else
    return x1 < x2;
  });

  // zeroes (a = b = 0) can be placed anywhere

  random_shuffle(zeroes.begin(), zeroes.end());
  for (int i = 0; i < n; ++i) {
    cout << name[order[i]] << endl;
    if (!zeroes.empty() && rand() * (n - i) < zeroes.size() * RAND_MAX) {
      // blend in zeroes regularly
      cout << zeroes.back() << endl;
      zeroes.pop_back();
    }
  }
  for (auto name: zeroes) cout << name << endl;

  return 0;
}

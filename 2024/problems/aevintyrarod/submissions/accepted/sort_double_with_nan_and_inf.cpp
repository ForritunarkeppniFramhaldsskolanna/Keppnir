#include "bits/stdc++.h"

using namespace std;

multimap<double, string> ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, x; cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    string name; cin >> name;
    int a, b; cin >> a >> b;
    ans.insert({double(a) / b, name});
  }

  for (auto& it : ans) {
    cout << it.second << endl;
  }

  return 0;
}

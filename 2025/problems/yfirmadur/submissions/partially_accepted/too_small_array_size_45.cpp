#include <iostream>
#include <set>
#include <cassert>

using namespace std;

using lli = long long int;

int p[390000];
int alias[390000];
int realid[390000];
bool unalived[390000];
set<int> unused;

int getp(int x) {
  if (unalived[p[x]]) return p[x] = getp(p[x]); else return p[x];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    alias[i] = i;
    realid[i] = i;
  }
  int nextid = n + 1;
  for (int i = 0; i < q; ++i) {
    unused.insert(n + i + 1);
    char c; cin >> c;
    int x; cin >> x;
    x = realid[x];
    if (c == '?') cout << alias[getp(x)] << '\n'; else
    if (c == '+') {
      assert(!unused.empty());
      int y = *unused.begin();
      unused.erase(unused.begin());
      realid[y] = nextid;
      alias[nextid] = y;
      p[nextid] = x;
      nextid++;
    } else {
      unalived[x] = true;
      unused.insert(alias[x]);
    }
  }

  return 0;
}

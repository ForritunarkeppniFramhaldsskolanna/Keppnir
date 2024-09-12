#include "bits/stdc++.h"

using namespace std;

unordered_map<string, int> a;

int n;
int order[30005];
vector<int> g[30005];
vector<int> comp;
int cccount = 0;
vector<vector<int>> comps;

int indeg[30005];
int ans[30005];

bitset<30000> dp[30005];

int tin[30005];
int time_ = 0;
vector<int> stck;
vector<int> topo;

int dfs(int v) {
  int low = tin[v] = ++time_;
  stck.push_back(v);

  for (auto w : g[v]) if (comp[w] < 0) low = min(low, tin[w] ? tin[w] : dfs(w));

  if (low == tin[v]) {
    int cur;
    vector<int> new_comp;
    do {
      cur = stck.back();
      stck.pop_back();
      comp[cur] = cccount;
      new_comp.push_back(cur);
    } while (cur != v);

    comps.emplace_back(new_comp);
    topo.push_back(cccount);
    cccount++;
  }
  return tin[v] = low;
}

int cnt;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  comp.resize(n, -1);
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    if (a.find(s) == a.end()) {
      a[s] = cnt++;
    }
    int v = a[s];
    order[i] = v;
    int k; cin >> k;
    for (int j = 0; j < k; ++j) {
      string t; cin >> t; if (t[0] > 'Z') continue;
      if (a.find(t) == a.end()) {
        a[t] = cnt++;
      }
      int w = a[t];
      if (w != v) g[v].push_back(w);
    }
  }

  for (int i = 0; i < n; ++i) if (comp[i] < 0) dfs(i);

  vector<vector<int>> sg(cccount);
  for (int i = 0; i < n; ++i) {
    // duplicates but who cares
    for (auto w : g[i]) if (comp[i] != comp[w]) sg[comp[i]].push_back(comp[w]);
  }
  for (int i = 0; i < cccount; ++i) {
    int cc = topo[i];
    for (auto w : sg[cc]) dp[cc] |= dp[w];
    for (auto w : comps[cc]) dp[cc].set(w);
    ans[cc] = dp[cc].count();
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[comp[order[i]]] << '\n';
  }

  return 0;
}

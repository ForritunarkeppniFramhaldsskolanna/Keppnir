#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define rep(i,a,b) for(auto i = (a); i < (b); ++i)

struct unionfind {
  vi p;
  int c;
  unionfind(int n) : p(n, -1), c(n) { }
  int find(int x) {
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }
  bool united(int x, int y) {
    return find(x) == find(y);
  }
  void unite(int x, int y) {
    int a = find(x), b = find(y);
    if(a == b) return;
    if(p[a] > p[b]) swap(a, b);
    p[a] += p[b];
    p[b] = a;
    c--;
    return;
  }
  int size(int x) {
    return -p[find(x)];
  }
};

vector<bool> visited;
vi order;
void scc_dfs(const vvi &adj, int u) {
  int v; visited[u] = true;
  rep(i,0,adj[u].size())
    if (!visited[v = adj[u][i]]) scc_dfs(adj, v);
  order.push_back(u); }
pair<unionfind, vi> scc(const vvi &adj) {
  int n = adj.size(), u, v;
  order.clear();
  unionfind uf(n); vi dag; vvi rev(n);
  rep(i,0,n) rep(j,0,adj[i].size()) rev[adj[i][j]].push_back(i);
  visited.resize(n);
  fill(visited.begin(), visited.end(), false);
  rep(i,0,n) if (!visited[i]) scc_dfs(rev, i);
  fill(visited.begin(), visited.end(), false);
  stack<int> S;
  for (int i = n-1; i >= 0; i--) {
    if (visited[order[i]]) continue;
    S.push(order[i]), dag.push_back(order[i]);
    while (!S.empty()) {
      visited[u = S.top()] = true, S.pop();
      uf.unite(u, order[i]);
      rep(j,0,adj[u].size())
        if (!visited[v = adj[u][j]]) S.push(v); } }
  return pair<unionfind, vi>(uf, dag); }

const int N = 1 << 15;
bitset<N> reach[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k; string s; cin >> n;
    vvi g(n, vi());
    unordered_map<string,int> ind;
    vector<int> outp_ind(n);
    ind.max_load_factor(0.5);
    for(int i = 0; i < n; ++i) {
        cin >> s >> k;
        if(!ind.count(s)) {
            int x = ind.size();
            ind[s] = x;
        }
        int y = ind[s];
        outp_ind[i] = y;
        for(int j = 0; j < k; ++j) {
            cin >> s;
            if(islower(s[0])) continue;
            if(!ind.count(s)) {
                int x = ind.size();
                ind[s] = x;
            }
            g[y].push_back(ind[s]);
        }
    }
    auto [uf, dag] = scc(g);
    for(int i = 0; i < n; ++i)
        reach[i].reset();
    for(int i = 0; i < n; ++i)
        reach[uf.find(i)].set(i);
    vvi h(n, vi());
    for(int i = 0; i < n; ++i) {
        for(int j : g[i]) {
            if(uf.find(i) == uf.find(j)) continue;
            h[uf.find(i)].push_back(uf.find(j));
        }
    }
    for(int x : dag) {
        int i = uf.find(x);
        for(int j : h[i]) {
            reach[i] |= reach[j];
        }
    }
    for(int i = 0; i < n; ++i)
        cout << reach[uf.find(outp_ind[i])].count() << '\n';
}


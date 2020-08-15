#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define rep(i,a,b) for(auto i = (a); i < (b); ++i)

struct union_find {
  vi p; union_find(int n) : p(n, -1) { }
  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
  bool unite(int x, int y) {
    int xp = find(x), yp = find(y);
    if (xp == yp) return false;
    if (p[xp] > p[yp]) swap(xp,yp);
    p[xp] += p[yp], p[yp] = xp;
    return true; }
  int size(int x) { return -p[find(x)]; } };

const ll ID = 0;
ll f(ll a, ll b) { return max(a, b); }
struct node {
  int l, r;
  ll x;
  node() {}
  node(int _l, int _r) : l(_l), r(_r), x(0) { }
  node(int _l, int _r, ll _x) : node(_l,_r) { x = _x; }
  node(node a, node b) : node(a.l,b.r) { x = f(a.x, b.x); }
  void update(ll v) { x = v; } };

struct segment_tree {
  int n;
  vector<node> arr;
  segment_tree() { }
  segment_tree(const vector<ll> &a) : n(a.size()), arr(4*n) {
    mk(a,0,0,n-1); }
  node mk(const vector<ll> &a, int i, int l, int r) {
    int m = (l+r)/2;
    return arr[i] = l > r ? node(l,r) :
      l == r ? node(l,r,a[l]) :
      node(mk(a,2*i+1,l,m),mk(a,2*i+2,m+1,r)); }
  node update(int at, ll v, int i=0) {
    int hl = arr[i].l, hr = arr[i].r;
    if (at < hl || hr < at) return arr[i];
    if (hl == at && at == hr) {
      arr[i].update(v); return arr[i]; }
    return arr[i] =
      node(update(at,v,2*i+1),update(at,v,2*i+2)); }
  node query(int l, int r, int i=0) {
    int hl = arr[i].l, hr = arr[i].r;
    if (r < hl || hr < l) return node(hl,hr);
    if (l <= hl && hr <= r) return arr[i];
    return node(query(l,r,2*i+1),query(l,r,2*i+2)); } };

struct HLD {
  int n, curhead, curloc;
  vi sz, head, parent, loc;
  vvi adj; segment_tree values;
  HLD(int _n) : n(_n), sz(n, 1), head(n),
                parent(n, -1), loc(n), adj(n) {
    vector<ll> tmp(n, ID); values = segment_tree(tmp); }
  void add_edge(int u, int v) {
    adj[u].push_back(v); adj[v].push_back(u); }
  void update_cost(int u, int v, ll c) {
    if (parent[v] == u) swap(u, v); assert(parent[u] == v);
    values.update(loc[u], c); }
  int csz(int u) {
    rep(i,0,adj[u].size()) if (adj[u][i] != parent[u])
      sz[u] += csz(adj[parent[adj[u][i]] = u][i]);
    return sz[u]; }
  void part(int u) {
    head[u] = curhead; loc[u] = curloc++;
    int best = -1;
    rep(i,0,adj[u].size())
      if (adj[u][i] != parent[u] &&
          (best == -1 || sz[adj[u][i]] > sz[best]))
        best = adj[u][i];
    if (best != -1) part(best);
    rep(i,0,adj[u].size())
      if (adj[u][i] != parent[u] && adj[u][i] != best)
        part(curhead = adj[u][i]); }
  void build(int r = 0) {
    curloc = 0, csz(curhead = r), part(r); }
  int lca(int u, int v) {
    vi uat, vat; int res = -1;
    while (u != -1) uat.push_back(u), u = parent[head[u]];
    while (v != -1) vat.push_back(v), v = parent[head[v]];
    u = (int)uat.size() - 1, v = (int)vat.size() - 1;
    while (u >= 0 && v >= 0 && head[uat[u]] == head[vat[v]])
      res = (loc[uat[u]] < loc[vat[v]] ? uat[u] : vat[v]),
      u--, v--;
    return res; }
  ll query_upto(int u, int v) { ll res = ID;
    while (head[u] != head[v])
      res = f(res, values.query(loc[head[u]], loc[u]).x),
      u = parent[head[u]];
    return f(res, values.query(loc[v] + 1, loc[u]).x); }
  ll query(int u, int v) { int l = lca(u, v);
    return f(query_upto(u, l), query_upto(v, l)); } };

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, q, l1, l2, d1, d2;
    cin >> n >> m;
    ll v[n][m];
    rep(i,0,n) rep(j,0,m) cin >> v[i][j];
    union_find uf(n * m);
    vector<vector<ll> > e, ep;
    rep(i,0,n) rep(j,0,m) {
        if(i > 0) e.push_back(vector<ll>({max(v[i][j], v[i - 1][j]), i * m + j, (i - 1) * m + j}));
        if(j > 0) e.push_back(vector<ll>({max(v[i][j], v[i][j - 1]), i * m + j, i * m + j - 1}));
        if(i < n - 1) e.push_back(vector<ll>({max(v[i][j], v[i + 1][j]), i * m + j, (i + 1) * m + j}));
        if(j < m - 1) e.push_back(vector<ll>({max(v[i][j], v[i][j + 1]), i * m + j, i * m + j + 1}));
    }
    sort(e.begin(), e.end());
    HLD hld(n * m);
    for(auto v : e) {
        if(uf.unite(v[1], v[2])) {
            hld.add_edge(v[1], v[2]);
            ep.push_back(v);
        }
    }
    hld.build();
    for(auto v : ep) {
        hld.update_cost(v[1], v[2], v[0]);
    }
    cin >> q;
    while(q--) {
        cin >> l1 >> d1 >> l2 >> d2;
        l1--; d1--; l2--; d2--;
        if(l1 == l2 && d1 == d2) cout << v[l1][d1] << '\n';
        else cout << hld.query(l1 * m + d1, l2 * m + d2) << '\n';
    }
}

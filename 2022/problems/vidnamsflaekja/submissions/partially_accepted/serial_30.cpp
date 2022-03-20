#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

const ll mod = 1e9 + 7;

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

ll egcd(ll a, ll b, ll& x, ll& y) {
  if(b == 0) { x = 1; y = 0; return a; }
  ll d = egcd(b, a % b, x, y);
  x -= a / b * y; swap(x, y); return d; }

ll mod_inv(ll a, ll m) {
  ll x, y, d = egcd(a, m, x, y);
  return d == 1 ? (x%m+m)%m : -1; }

void add_edge(vvii &g, int a, int b, int x) {
    for(int t = 0; t < 2; ++t) {
        bool found = false;
        for(int j = 0; j < g[a].size(); ++j) {
            if(g[a][j].second == b) {
                found = true;
                g[a][j].first = mod_inv(mod_inv(x, mod) + mod_inv(g[a][j].first, mod), mod);
            }
        }
        if(!found) g[a].push_back(ii(x, b));
        swap(a, b);
    }
}

bool collapse_serial(vvii &g) {
    bool ch = false;
    for(int i = 0; i < g.size(); ++i) {
        if(g[i].size() == 1) {
            int x = g[i][0].second;
            ii opp(g[i][0].first, i);
            g[i].clear();
            g[x].erase(find(g[x].begin(), g[x].end(), opp));
            ch = true;
        }
        if(g[i].size() == 2) {
            int x = g[i][0].second;
            int y = g[i][1].second;
            ii oppx(g[i][0].first, i);
            ii oppy(g[i][1].first, i);
            ll res = mod_inv(mod_inv(g[i][0].first, mod) + mod_inv(g[i][1].first, mod), mod);
            g[i].clear();
            g[x].erase(find(g[x].begin(), g[x].end(), oppx));
            g[y].erase(find(g[y].begin(), g[y].end(), oppy));
            add_edge(g, x, y, res);
            ch = true;
        }
    }
    return ch;
}

bool ready(vvii &g, int s, int t) {
    unionfind uf(g.size());
    for(int i = 0; i < g.size(); ++i) {
        for(ii x : g[i]) {
            if(i == s && x.second == t) continue;
            if(i == t && x.second == s) continue;
            uf.unite(i, x.second);
        }
    }
    return !uf.united(s, t);
}

int main() {
    int n, m, s, t, a, b, x;
    cin >> n >> m >> s >> t;
    s--; t--;
    vvii g(n, vii());
    for(int i = 0; i < m; ++i) {
        cin >> a >> b >> x;
        a--; b--;
        add_edge(g, a, b, x);
    }
    while(!ready(g, s, t)) {
        assert(collapse_serial(g));
    }
    for(ii p : g[s]) {
        if(p.second == t) {
            cout << p.first << '\n';
        }
    }
}

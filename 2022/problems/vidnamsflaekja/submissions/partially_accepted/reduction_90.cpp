#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const ll mod = 1e9 + 7;

ll egcd(ll a, ll b, ll& x, ll& y) {
  if(b == 0) { x = 1; y = 0; return a; }
  ll d = egcd(b, a % b, x, y);
  x -= a / b * y; swap(x, y); return d; }

ll mod_inv(ll a, ll m) {
  ll x, y, d = egcd(a, m, x, y);
  return d == 1 ? (x%m+m)%m : -1; }

void add_edge(vector<vector<ll>> &adj, int a, int b, ll x) {
    if(adj[a][b] == -1) {
        adj[a][b] = adj[b][a] = x;
    } else {
        adj[a][b] = mod_inv(mod_inv(adj[a][b], mod) + mod_inv(x, mod), mod);
        adj[b][a] = mod_inv(mod_inv(adj[b][a], mod) + mod_inv(x, mod), mod);
    }
}

int main() {
    int n, m, s, t, a, b, x;
    cin >> n >> m >> s >> t;
    s--; t--;
    vvii g(n, vii());
    vector<vector<ll>> adj(n, vector<ll>(n, -1));
    for(int i = 0; i < m; ++i) {
        cin >> a >> b >> x;
        a--; b--;
        add_edge(adj, a, b, x);
    }
    vector<int> deg(n, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(adj[i][j] != -1) deg[i]++;
        }
    }
    queue<int> deg1, deg2;
    for(int i = 0; i < n; ++i) {
        if(deg[i] == 2) deg2.push(i);
        if(deg[i] == 1) deg1.push(i);
    }
    while(deg1.size() + deg2.size() > 0) {
        if(!deg1.empty()) {
            int cur = deg1.front();
            deg1.pop();
            if(cur == s || cur == t) continue;
            if(deg[cur] != 1) continue;
            int x = -1, y = -1;
            for(int i = 0; i < n; ++i) {
                if(adj[cur][i] == -1) continue;
                if(x == -1) x = i;
                else y = i;
            }
            assert(x != -1); assert(y == -1);
            adj[cur][x] = adj[x][cur] = -1;
            deg[cur] = 0;
            deg[x]--;
            if(deg[x] == 2) deg2.push(x);
            if(deg[x] == 1) deg1.push(x);
            continue;
        }
        int cur = deg2.front();
        deg2.pop();
        if(cur == s || cur == t) continue;
        if(deg[cur] != 2) continue;
        int x = -1, y = -1, z = -1;
        for(int i = 0; i < n; ++i) {
            if(adj[cur][i] == -1) continue;
            if(x == -1) x = i;
            else if(y == -1) y = i;
            else z = i;
        }
        assert(x != -1); assert(y != -1); assert(z == -1);
        if(adj[x][y] != -1) {
            deg[x]--, deg[y]--;
            if(deg[x] == 2) deg2.push(x);
            if(deg[y] == 2) deg2.push(y);
            if(deg[x] == 1) deg1.push(x);
            if(deg[y] == 1) deg1.push(y);
        }
        deg[cur] = 0;
        add_edge(adj, x, y, (adj[x][cur] + adj[y][cur]) % mod);
        adj[cur][x] = -1;
        adj[cur][y] = -1;
        adj[x][cur] = -1;
        adj[y][cur] = -1;
    }
    /*for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(adj[i][j] != -1) cout << i << ' ' << j << endl;
        }
    }*/
    cout << adj[s][t] << '\n';
}

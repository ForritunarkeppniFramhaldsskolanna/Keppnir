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

int main() {
    int n, m, s, t, a, b, x;
    cin >> n >> m >> s >> t;
    s--; t--;
    vvii g(n, vii());
    vector<vector<ll>> adj(n, vector<ll>(n, -1));
    for(int i = 0; i < m; ++i) {
        cin >> a >> b >> x;
        a--; b--;
        if(adj[a][b] == -1) {
            adj[a][b] = adj[b][a] = x;
        } else {
            adj[a][b] = mod_inv(mod_inv(adj[a][b], mod) + mod_inv(x, mod), mod);
            adj[b][a] = mod_inv(mod_inv(adj[b][a], mod) + mod_inv(x, mod), mod);
        }
    }
    vector<ll> dist(n, -1);
    dist[s] = 0;
    vector<int> q;
    q.push_back(s);
    while(q.size() > 0) {
        int cur = q.back();
        q.pop_back();
        for(int i = 0; i < n; ++i) {
            if(adj[cur][i] == -1) continue;
            if(dist[i] != -1) continue;
            dist[i] = (adj[cur][i] + dist[cur]) % mod;
            q.push_back(i);
        }
    }
    cout << dist[t] << '\n';
}

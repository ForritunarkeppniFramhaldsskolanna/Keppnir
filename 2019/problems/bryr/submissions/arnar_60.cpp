#include <bits/stdc++.h>
#pragma GCC target("arch=sandybridge")
#pragma GCC optimize("O3")
#pragma GCC optimize("expensive-optimizations")
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
#define fs first
#define sc second
#define pb push_back
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vvii adj(n);
    rep(i,0,m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back(ii(b,c));
        adj[b].push_back(ii(a,c));
    }

    deque<int> q;
    q.push_back(0);
    vi dist(n, INF);
    vector<bool> vis(n);
    dist[0] = 0;
    while(!q.empty())
    {
        int cur = q.front(); q.pop_front();
        if(vis[cur]) continue;
        vis[cur] = true;
        iter(it, adj[cur])
        {
            if(vis[it->first]) continue;
            dist[it->first] = min(dist[it->first], dist[cur] + it->second);
            q.push_back(it->first);
        }
    }

    cout << dist[n-1] << endl;

    return 0;
}

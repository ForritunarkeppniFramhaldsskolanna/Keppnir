#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;

vii edg[100005];
int djikstra(int s, int e) {
	bool vis[100005];
	int dist[100005];
	memset(vis,false,sizeof(vis));
	rep(i,0,100005) dist[i] = INF;
	priority_queue<ii,vii,greater<ii>> pq;
	pq.push(ii(0,s));
	dist[s] = 0;
	while(!pq.empty()) {
		ii cur = pq.top();
		pq.pop();
		if(vis[cur.sc]) continue;
		vis[cur.sc] = true;
		rep(i,0,edg[cur.sc].size()) {
			ii nx = edg[cur.sc][i];
			if(!vis[nx.sc]) {
				dist[nx.sc] = min(dist[nx.sc], dist[cur.sc]+nx.fs);
				pq.push(ii(dist[nx.sc], nx.sc));
			}
		}
	}
    return dist[e];
}

int main() {
    cin.sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    rep(i,0,m) {
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        edg[a].pb(ii(c,b));
        edg[b].pb(ii(c,a));
    }
    cout << djikstra(0,n-1) << endl;
    return 0;
}



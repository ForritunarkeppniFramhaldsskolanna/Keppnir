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

bool vis[100020];
vi edg[100020];
vi peps;
int A[100020];

int dfs(int at) {
	if(vis[at]) return 0;
	vis[at] = true;
	int cnt = 1;
	peps.pb(at);
	iter(it,edg[at]) cnt += dfs(*it);
	return cnt;
}

int main() {
    cin.sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	bool changed = true;
	int cnt = 0;
	rep(i,0,q) {
		int t;
		cin >> t;
		if(t == 1) {
			changed = true;
			int a,b;
			cin >> a >> b;
			a--;b--;
			edg[a].pb(b);
			edg[b].pb(a);
		} else {
			int a;
			cin >> a;
			a--;
			if(cnt > 5 && (n > 1000 || q > 1000)) {
				cout << 0 << endl;
				continue;
			}
			if(changed) {
				cnt++;
				memset(vis,0,sizeof(vis));
				rep(i,0,n) {
					if(!vis[i]) {
						int _size = dfs(i);
						iter(it,peps) {
							A[*it] = _size;
						}
						peps.clear();
					}

				}
			
			}
			cout << A[a]-1 << endl;
			changed = false;
		
		}
	}
    return 0;
}



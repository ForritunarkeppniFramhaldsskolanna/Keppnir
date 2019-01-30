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

set<string> can_not_be;
map<string,vector<string>> edg;

set<string> vis;
vector<string> ans;

void dfs(string a) {
	if(vis.find(a) != vis.end()) return;
	vis.insert(a);
	iter(it,edg[a]) dfs(*it);
	ans.pb(a);
}


typedef pair<int,string> iss;

int main() {
    cin.sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	vector<string> A(n);
	rep(i,0,n) cin >> A[i];
	rep(i,0,k) {
		string a,b,c;
		cin >> a >> b >> c;
		if(b == "<") {
			edg[c].pb(a);
			can_not_be.insert(a);
		} else {
			edg[a].pb(c);
			can_not_be.insert(c);
		}
	}
	rep(i,0,n) {
		if(can_not_be.find(A[i]) == can_not_be.end()) {
			dfs(A[i]);
			if(ans.size() != n) {
				cout << "veit ekki" << endl;
				return 0;
			}
			iter(it,ans) cout << *it << " ";
			cout << endl;
			return 0;
		}
	}
	cout << "veit ekki" << endl;
    return 0;
}



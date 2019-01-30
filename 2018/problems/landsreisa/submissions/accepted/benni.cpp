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

typedef long double ld;
typedef pair<ld,ld> dd;

ld dadist(dd a, dd b) {
	return sqrt(pow(a.fs-b.fs,2) + pow(a.sc-b.sc,2));
}

int main() {
    cin.sync_with_stdio(false);
	srand(time(NULL));
	int n;
	cin >> n;
	vector<dd> k(n);
	rep(i,0,n) {
		cin >> k[i].fs >> k[i].sc;
	}
	ld mx = 10000000000;
	vi ans;
	clock_t begin = clock();
	while(true) {
		clock_t end = clock();
		if(double(end-begin) / CLOCKS_PER_SEC > 4.98) break;
		bool vis[500];
		ld dist = 0;
		vi hold;
		memset(vis,0,sizeof(vis));
		vis[0] = true;
		hold.pb(0);
		rep(i,1,n) {
			vector<dd> D;
			rep(j,0,n) {
				if(!vis[j]) {
					D.pb(dd(dadist(k[hold[i-1]], k[j]), j));
				}
			}
			int tots = D.size();
			sort(D.begin(), D.end());
			for(int i = D.size()-1; i >= 0; i--) {
				if(D[i].fs > D[0].fs*1.10) {
					D.pop_back();
				}
			}
			int index = rand()%(int(D.size()));
			hold.pb(int(D[index].sc));
			vis[int(D[index].sc)] = true;
			dist += D[index].fs;
		}
		dist += dadist(k[hold[0]], k[hold[n-1]]);


		if(dist < mx) {
			mx = dist;
			ans = hold;
		}
	}
	iter(it,ans) cout << *it << " ";
	cout << endl;
    return 0;
}



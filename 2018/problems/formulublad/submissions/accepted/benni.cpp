#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T> ll size(const T &x) { return x.size(); }
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const ll INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;

ll n,L;
vii A;
ll memo[1020][1020];

ll dp(ll at, ll weight) {
	if(weight > L) return -99999999999999999ll;
	if(at >= n) return memo[at][weight] = 0;
	if(memo[at][weight] != -1) return memo[at][weight];
	return memo[at][weight] = max(dp(at+1,weight+A[at].fs)+A[at].sc, dp(at+1,weight));
}

vi ans;

void get(ll at, ll weight, ll need) {
	if(at >= n) return;
	if(dp(at+1, weight+A[at].fs) == need-A[at].sc) {
		ans.pb(at);
		need -= A[at].sc;
		get(at+1,weight+A[at].fs, need);
	} else {
		get(at+1,weight,need);
	}
}

int main() {
    cin.sync_with_stdio(false);
	memset(memo,-1,sizeof(memo));
	cin >> n >> L;
	A = vii(n);
	rep(i,0,n) cin >> A[i].fs >> A[i].sc;
	ll mx = dp(0,0);
	get(0,0,mx);
	cout << ans.size() << " " << mx << endl;
	iter(it,ans) cout << *it << " ";
	cout << endl;
    return 0;
}



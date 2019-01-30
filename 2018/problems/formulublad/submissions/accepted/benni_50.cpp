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
typedef pair<int,ii> iii;

bool compare(iii a, iii b) {
	if(a.sc.fs == b.sc.fs) {
		return a.sc.sc < b.sc.sc;
	}
	return a.sc.fs > b.sc.fs;
}

int main() {
    cin.sync_with_stdio(false);
	ll n,L;
	cin >> n >> L;
	vector<iii> A(n);
	rep(i,0,n) {
		cin >> A[i].sc.sc >> A[i].sc.fs;
		A[i].fs = i;
	}
	sort(A.begin(), A.end(), compare);
	vi ans;
	ll sum = 0;
	ll weight = 0;
	rep(i,0,n) {
		if(weight+A[i].sc.sc <= L) {
			sum += A[i].sc.fs;
			weight += A[i].sc.sc;
			ans.pb(A[i].fs);
		}
	}
	cout << ans.size() << " " << sum << endl;
	iter(it,ans) cout << *it << " ";
	cout << endl;
    return 0;
}



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

int main() {
    cin.sync_with_stdio(false);
	int n,q;
	bool rev = false;
	int cnt = 0;
	cin >> n >> q;
	vi A(n,0);
	rep(i,0,q) {
		int t;
		cin >> t;
		if(t == 1) {
			int at;
			cin >> at;
			at--;
			A[at] = 1-A[at];
			if(A[at] == 0) cnt--;
			else cnt++;
		} else if(t == 3) {
			if(rev) cout << n-cnt << endl;
			else cout << cnt << endl;
		}
	}
    return 0;
}

		

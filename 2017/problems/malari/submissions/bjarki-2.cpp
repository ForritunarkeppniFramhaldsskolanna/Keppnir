#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = 2147483647;

int main() {
    int n, m;
    cin >> n >> m;
    vi arr(n);
    rep(i,0,m) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        arr[l]++;
        if (r+1 < n) arr[r+1]--;
    }
    int sm = 0,
        cur = 0;
    rep(i,0,n) {
        cur += arr[i];
        sm += (cur > 0);
    }
    cout << sm << endl;
	if(sm*2 > n){
		cout << "The Mexicans took our jobs! Sad!" << endl;
	}else{
		cout << "The Mexicans are Lazy! Sad!" << endl;
	}
    return 0;
}


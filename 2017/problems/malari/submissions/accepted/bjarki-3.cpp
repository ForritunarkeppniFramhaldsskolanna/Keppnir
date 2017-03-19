#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 2147483647;

int main() {
    ll n, m;
    cin >> n >> m;
    vii ev;

    rep(i,0,m) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        ev.push_back(ii(l,-1));
        ev.push_back(ii(r+1,1));
    }
    ev.push_back(ii(n,-2));
    sort(ev.begin(), ev.end());

    ll d = 0,
        sm = 0,
        last = 0;
    rep(i,0,size(ev)) {
        if (d > 0) {
            sm += ev[i].first - last;
        }
        if (ev[i].second == -2) {
            break;
        }
        d -= ev[i].second;
        last = ev[i].first;
    }

    cout << sm << endl;
	if(sm*2 > n){
		cout << "The Mexicans took our jobs! Sad!" << endl;
	}else{
		cout << "The Mexicans are Lazy! Sad!" << endl;
	}

    return 0;
}


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


ll n,k;
vi A;
vii T[100050];
ll memo[100050];

ll dp(ll at) {
    if(at >= n) return 0;
    if(memo[at] != -1) return memo[at];
    ll mx = dp(at+1) + (k == 1 ? 2 : 0);
    rep(i,0,T[at].size()) {
        mx = max(mx, dp(T[at][i].first+1) + (1LL<<T[at][i].second));
    }
    return memo[at] = mx;
}

ll P[40][100050];

int main() {
    cin.sync_with_stdio(false);
    memset(memo,-1,sizeof(memo));
    cin >> n >> k;
    A = vi(n);
    rep(i,0,n) cin >> A[i], A[i]-= 1;
    memset(P,0,sizeof(P));
    rep(i,0,n) P[A[i]][i+1] = 1;
    rep(i,0,33) rep(j,1,n+10) P[i][j] += P[i][j-1];

    rep(i,0,n) {
        rep(j,1,33) {
            ll lo = i, hi = n-1;
            ll bst = -1;
            while(lo <= hi) {
                ll mid = (lo+hi)/2;
                ll nm = 0;
                ll bad = 0;
                rep(z,0,32) {
                    ll cnt = P[z][mid+1]-P[z][i];
                    if(cnt >= k) nm += 1;
                    else if(cnt != 0) bad += 1;
                }
                if(nm > j) {
                    hi = mid-1;
                } else {
                    if(nm < j) {
                        lo = mid+1;
                    } else {
                        if(bad == 0) bst = mid;
                        hi = mid-1;
                    }
                }
            }
            if(bst != -1) {
                T[i].pb(ii(bst,j));
            }
        }
    }
    cout << dp(0) << endl;
    return 0;
}



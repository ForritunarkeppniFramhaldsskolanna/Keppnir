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
ll memo[1020];

ll dp(ll at) {
    if(at >= n) return 0;
    if(memo[at] != -1) return memo[at];
    vector<ll> CNT(33,0);
    ll mxbst = 0;
    ll bst = dp(at+1) + (k == 1 ? 2 : 0);
    rep(i,at,n) {
        CNT[A[i]] += 1;
        ll good = 0;
        ll bad = 0;
        rep(j,0,32) {
            if(CNT[j] != 0 && CNT[j] < k) bad++;
            else if(CNT[j] >= k) good += 1;
        }
        if(bad == 0 && good > mxbst) {
            assert(good != 0);
            bst = max(bst, dp(i+1)+(1LL<<good));
            mxbst = max(mxbst, good);
        }
    }
    return memo[at] = bst;
}

int main() {
    cin.sync_with_stdio(false);
    memset(memo,-1,sizeof(memo));
    cin >> n >> k;
    A = vi(n);
    rep(i,0,n) cin >> A[i], A[i]--;
    cout << dp(0) << endl;
    return 0;
}



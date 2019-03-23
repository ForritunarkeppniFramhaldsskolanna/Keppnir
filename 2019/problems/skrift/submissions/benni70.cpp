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

int main() {
    cin.sync_with_stdio(false);
    ll n,m,q;
    cin >> n >> m >> q;
    vii M(m);
    rep(i,0,m) cin >> M[i].fs >> M[i].sc;
    vii Q(q);
    rep(i,0,q) cin >> Q[i].fs >> Q[i].sc;
    ll cnt[100050];
    memset(cnt,0,sizeof(cnt));
    ll at = 0;
    rep(i,0,q) {
        if(Q[i].fs == 1) {
            at += Q[i].sc;
        } else {
            cnt[at] -= 1; 
            cnt[at-Q[i].sc] += 1;
            at -= Q[i].sc;
        }
    }
    vi P,P2;
    rep(i,0,n+1) cnt[i+1] += cnt[i];
    rep(i,0,n) P2.pb(cnt[i]);
    rep(i,0,m) {
        rep(j,0,M[i].fs) P.pb(M[i].sc);
    }

    sort(P2.rbegin(), P2.rend());
    sort(P.rbegin(), P.rend());

    ll sm = 0;
    rep(i,0,n) sm += P2[i]*P[i];
    cout << sm << endl;

    return 0;
}



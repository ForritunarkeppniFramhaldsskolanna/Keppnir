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
    rep(i,0,m) cin >> M[i].sc >> M[i].fs;
    sort(M.rbegin(), M.rend());
    vii I;
    ll at = 0;
    rep(i,0,q) {
        ll op, y;
        cin >> op >> y;
        if(op == 1) { // write
            at += y;
        } else { // remove
            I.pb(ii(at-y+1,1));
            I.pb(ii(at+1,0));
            at -= y;
        }
        assert(at >= 0);
        assert(at <= n);
    }
    assert(at == n);
    sort(I.begin(), I.end());
    //rep(i,0,I.size()) cout << "Da : " << I[i].fs << " " << I[i].sc << endl;
    vii RI; // First number how often, second number is how large llerval
    ll cnt = 0;
    ll last = 0;
    rep(i,0,I.size()) {
        vii all;
        rep(j,i,I.size()) {
            if(I[j].fs == I[i].fs) {
                all.pb(I[j]);
            } else break;
        }
        bool found_end = false;
        rep(j,0,all.size()) {
            if(all[j].sc == 0) found_end = true;
        }
        if(cnt != 0) {
            RI.pb(ii(cnt, I[i].fs-last));
        }
        rep(j,0,all.size()) {
            if(all[j].sc == 0) cnt -= 1;
            else cnt += 1;
        }
        i += ll(all.size());
        i -= 1;
        last = I[i].fs;
    }
    sort(RI.rbegin(), RI.rend());
    //rep(i,0,RI.size()) cout << "Hello : " << RI[i].fs << " " << RI[i].sc << endl; 
    ll m_at = 0;
    ll sm = 0;
    rep(i,0,RI.size()) {
        ll left = RI[i].sc;
        //cout << sm << endl;
        while(left > 0) {
            if(M[m_at].sc >= left) {
                sm += left * RI[i].fs * M[m_at].fs;
                M[m_at].sc -= left;
                left = 0;
            } else {
                sm += M[m_at].sc * M[m_at].fs * RI[i].fs;
                left -= M[m_at].sc;
                M[m_at].sc = 0;
                m_at += 1;
            }
        }
    }
    assert(sm >= 0);
    cout << sm << endl;

    return 0;
}



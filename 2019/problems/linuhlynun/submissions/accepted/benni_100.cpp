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
    ll n;
    cin >> n;
    vii A(n);
    rep(i,0,n) cin >> A[i].fs >> A[i].sc;
    sort(A.begin(), A.end());
    ll l = 0, r = 0;
    ll val = 0;
    rep(i,0,n) r += A[i].sc;
    rep(i,0,n) val = (A[i].fs-A[0].fs) * A[i].sc;
    ll bst = A[0].fs;
    ll bstval = val;
    rep(i,0,n-1) {
        l += A[i].sc;
        r -= A[i].sc;
        ll dist = A[i+1].fs-A[i].fs;
        val += l*dist;
        val -= r*dist;
        if(val < bstval) {
            bst = A[i+1].fs;
            val = bstval;
        }
    }
    cout << bst << endl;
    return 0;
}



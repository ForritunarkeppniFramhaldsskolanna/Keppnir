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
    int n;
    cin >> n;
    vi A(n);
    rep(i,0,n) cin >> A[i];
    vi P(n);
    rep(i,0,n) P[n-A[i]] = i+1;
    rep(i,0,n) cout << P[i] << " ";
    cout << endl;
    return 0;
}



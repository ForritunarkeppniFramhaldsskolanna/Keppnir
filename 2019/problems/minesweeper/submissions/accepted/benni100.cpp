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


char R[520][520];

int main() {
    cin.sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    rep(i,0,n) rep(j,0,m) R[i][j] = '.';
    rep(i,0,k) {
        int x,y;
        cin >> x >> y;
        x--;y--;
        R[x][y] = '*';
    }
    rep(i,0,n) {
        rep(j,0,m) cout << R[i][j];
        cout << endl;
    }
    return 0;
}



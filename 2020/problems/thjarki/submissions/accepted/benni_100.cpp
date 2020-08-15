#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const ll INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;
typedef unsigned long long ull;

template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

char C[510][510];
ii T[510][510][40];

int main() {
    cin.sync_with_stdio(false);
    unordered_map<char,ii> dir;
    dir['v'] = ii(1,0);
    dir['>'] = ii(0,1);
    dir['<'] = ii(0,-1);
    dir['^'] = ii(-1,0);

    ll n,m;
    cin >> n >> m;

    rep(i,0,n) rep(j,0,m) {
        cin >> C[i][j];
        T[i][j][0] = ii(i+dir[C[i][j]].fs,j+dir[C[i][j]].sc);
    }

    for(ll z = 1; z < 40; z++) {
        rep(i,0,n) rep(j,0,m) {
            ii at = T[i][j][z-1];
            ii new_at = T[at.fs][at.sc][z-1];
            T[i][j][z] = new_at;
        }
    }
    ll q;
    cin >> q;
    rep(i,0,q) {
        ll x,y,k;
        cin >> x >> y >> k;
        x--;y--;
        ii at = ii(x,y);
        for(ll j = 33; j >= 0; j--) {
            ll t = (1ll<<j);
            if(t <= k) {
                at = T[at.fs][at.sc][j];
                k -= t;
            }
        }
        cout << at.fs+1 << " " << at.sc+1 << endl;
    }
    return 0;
}












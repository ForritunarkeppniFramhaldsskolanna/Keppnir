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

bool vis[100050];

int main() {
    cin.sync_with_stdio(false);
    int n,d;
    cin >> n >> d;
    vi A(n);
    rep(i,0,n) cin >> A[i];
    int at = 0;
    int sm = 0;
    memset(vis,0,sizeof(vis));
    while(!vis[at]) {
        vis[at] = true;
        sm += A[at];
        at += d;
        at %= n;
    }
    cout << sm << endl;

    
    return 0;
}



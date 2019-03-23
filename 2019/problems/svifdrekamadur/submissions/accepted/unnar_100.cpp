#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31); // 2147483647

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) { return (a % b + b) % b; }

int main(){
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    vi v(n);
    rep(i,0,n) cin >> v[i];
    // nxt[i] holds the index of the first element after i that is greater than v[i]
    // prv[i] holds the index of the first element before i that is greater than v[i]
    vi nxt(n, -1), prv(n, -1);
    // {nxt,prv}_can_use[i] is true if there is no element between i and {nxt,prv}[i] that is equal to v[i]
    vector<bool> nxt_can_use(n, true), prv_can_use(n, true);
    for(int i=n-2; i >= 0; i--){
        int j = i+1;
        bool flag = true;
        while(j != -1 && v[j] <= v[i]){
            flag &= v[i] != v[j];
            j = nxt[j];
        }
        nxt[i] = j;
        nxt_can_use[i] = flag;
    }
    rep(i, 1, n){
        int j = i-1;
        bool flag = true;
        while(j != -1 && v[j] <= v[i]){
            flag &= v[i] != v[j];
            j = prv[j];
        }
        prv[i] = j;
        prv_can_use[i] = flag;
    }
    int ans = 0;
    rep(i,0,n){
        if(nxt[i] != -1 && nxt_can_use[i]) ans = max(ans, nxt[i]-i);
        if(prv[i] != -1 && prv_can_use[i]) ans = max(ans, i-prv[i]);
    }
    cout << ans << endl;
    return 0;
}

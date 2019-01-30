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

int dp[1010][1010];

int main(){
    cin.sync_with_stdio(false);
    int n, L;
    cin >> n >> L;
    vii formulas(n+1);
    rep(i,1,n+1){
        cin >> formulas[i].first >> formulas[i].second;
    }
    memset(dp, 0, sizeof(dp));
    rep(i,1,n+1){
        rep(j,1,L+1){
            if(formulas[i].first <= j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-formulas[i].first]+formulas[i].second);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    vi ans;
    int i = n, j = L;
    int sm = 0;
    while(i > 0){
        if(j >= formulas[i].first && (dp[i][j]-formulas[i].second == dp[i-1][j-formulas[i].first])){
            ans.push_back(i-1);
            sm += formulas[i].second;
            j -= formulas[i].first;
            i--;
        } else {
            i--;
        }
    }
    reverse(ans.begin(), ans.end());
    assert(sm == dp[n][L]);
    cout << size(ans) << " " << dp[n][L] << endl;
    rep(k,0,size(ans)) cout << ans[k] << " ";
    cout << endl;
    return 0;
}

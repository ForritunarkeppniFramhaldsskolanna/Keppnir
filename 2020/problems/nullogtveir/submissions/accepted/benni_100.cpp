#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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

string s;
ll memo[52][3][3][3][3];
ll dp(ll at, ll issame, ll has0, ll has2, ll putdown) {
    if(at >= s.size()) {
        if(!putdown) return 1;
        if(has0 || has2) return 1;
        return 0;
    }
    if(memo[at][issame][has0][has2][putdown] != -1) return memo[at][issame][has0][has2][putdown];
    ll cnt = 0;
    if(!issame) {
        cnt += dp(at+1,0, has0 ,1,1);
        cnt += dp(at+1,0,max(has0, ll(putdown == 1 ? 1 : 0)),has2, putdown);
    } else {
        if(2 <= s[at]-'0') {
            cnt += dp(at+1, 2 == s[at]-'0', has0, 1, 1);
        }
        cnt += dp(at+1, min(ll(0 == s[at]-'0' && putdown), issame), max(has0, ll(putdown == 1 ? 1 : 0)), has2, putdown);
    }
    return memo[at][issame][has0][has2][putdown] = cnt;
}



int main() {
    cin.sync_with_stdio(false);
    memset(memo,-1,sizeof(memo));
    cin >> s;
    cout << dp(0,1,0,0,0);
    return 0;
}












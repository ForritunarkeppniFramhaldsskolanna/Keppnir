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

int main() {
    cin.sync_with_stdio(false);
    ll n;
    cin >> n;
    map<string,ll> K;
    rep(i,0,n) {
        string x;
        ll y;
        cin >> x >> y;
        K[x] += y;
    }
    ll mx = 0;
    iter(it,K) mx = max(mx, it->second);
    iter(it,K) {
        if(it->second == mx) {
            cout << it->first << endl;
        }
    }
    return 0;
}



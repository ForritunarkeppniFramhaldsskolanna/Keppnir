#include <bits/stdc++.h>
#pragma GCC target("arch=sandybridge")
#pragma GCC optimize("O3")
#pragma GCC optimize("expensive-optimizations")
using namespace std;
template <class T> int Size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
#define fs first
#define sc second
#define pb push_back
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

ll slow(ll L, ll R, ll n)
{
    ll cnt = 0;
    rep(i,L,R+1) if(i%n == 0) cnt++;
    return cnt;
}

ll f(ll x, ll n)
{
    return x/n;
}

ll fast(ll L, ll R, ll n)
{
    return f(R, n) - f(L-1, n);
}

int main()
{
    ios_base::sync_with_stdio(false);

    ll L, R, k;
    cin >> L >> R >> k;
    vector<ll> arr(k);
    rep(i,0,k)
    {
        cin >> arr[i];
    }
    
    ll sm = 0;

    rep(i,1,1<<k)
    {
        ll num = 1, sign = -1;
        rep(j,0,k)
        {
            if(i&(1<<j)) num *= arr[j], sign *= -1;
            if(num > R) break;
        }
        if(num > R) continue;
        sm += sign * fast(L, R, num);
    }

    cout << sm << endl;
}

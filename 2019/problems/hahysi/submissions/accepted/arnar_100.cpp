#include <bits/stdc++.h>
#pragma GCC target("arch=sandybridge")
#pragma GCC optimize("O3")
#pragma GCC optimize("expensive-optimizations")
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
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

ll M = 1000000007;

ll choose2(ll x)
{
    if(x % 2 == 0)
    {
        return x/2 * (x-1) % M;
    }
    else
    {
        return (x+M-1)%M/2 * x % M;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll n, m;
    cin >> n >> m;
    n %= M;
    m %= M;
    
    ll cnt = choose2(n)*choose2(m)%M;    
    cout << cnt << endl;

    return 0;
}

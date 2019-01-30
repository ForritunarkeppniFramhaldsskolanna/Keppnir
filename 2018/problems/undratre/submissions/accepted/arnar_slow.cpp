#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
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

int main()
{
    ll n, k;
    cin >> n >> k;
    ll sm = 1;
    ll pow = 1;
    ll mxh = n+1;
    ll mnb = 1;
    ll mnh = 1;
    if(k == 1)
    {
        cout << n+1 << " " << n+1 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    if(k != 2) return 0;
    while(sm+pow*k <= n+1)
    {
        pow *= k;
        sm += pow;
        mnh += 1;
    }
    ll mxb;
    if(sm == n+1)
    {
        mxb = pow;
    }
    else
    {
        mnh++;
        mxb = pow;
        while(n-(sm-1) >= k)
        {
            sm += k;
            mxb += k-1;
        }
        ll left = n-(sm-1);
        mxb += max(0LL, left-1);
    }
    cout << mnh << " " << mxh << endl;
    cout << mnb << " " << mxb << endl;
    return 0;
}

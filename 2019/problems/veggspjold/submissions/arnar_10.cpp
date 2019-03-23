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

int main()
{
    ios_base::sync_with_stdio(false);
    
    int b, h, n;
    cin >> b >> h >> n;

    int ans = b*h;
    rep(i,0,n)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        ans -= (x2-x1)*(y2-y1);
    }

    cout << ans << endl;

    return 0;
}

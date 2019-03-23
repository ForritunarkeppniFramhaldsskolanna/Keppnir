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
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

#define MAXN 100000

int cnt[8*MAXN], arr[8*MAXN];
vi ys;

// update by u in range [a, b)
void update(int a, int b, int l, int r, int i, int u)
{
    a = max(a, l);
    b = min(b, r);
    if(a >= b) return;
    if(a == l && b == r) cnt[i] += u;
    else
    {
        int m = (l+r)/2;
        update(a, b, l, m, 2*i+1, u);
        update(a, b, m, r, 2*i+2, u);
    }
    if(cnt[i]) arr[i] = ys[r] - ys[l];
    else arr[i] = arr[2*i+1] + arr[2*i+2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    memset(cnt, 0, sizeof(cnt));
    memset(arr, 0, sizeof(arr));
    ll b, h, n;
    cin >> b >> h >> n;

    vvi rects(n);
    rep(i,0,n)
    {
        ll x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        ys.push_back(y1);
        ys.push_back(y2);
        rects[i].push_back(x1);
        rects[i].push_back(x2);
        rects[i].push_back(y1);
        rects[i].push_back(y2);
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int k = (int)ys.size();

    vvi evt(2*n);
    rep(i,0,n)
    {
        int l = distance(ys.begin(), lower_bound(ys.begin(), ys.end(), rects[i][2]));
        int r = distance(ys.begin(), lower_bound(ys.begin(), ys.end(), rects[i][3]));
        evt[2*i].push_back(rects[i][0]);
        evt[2*i].push_back(l);
        evt[2*i].push_back(r);
        evt[2*i].push_back(1); // add
        evt[2*i+1].push_back(rects[i][1]);
        evt[2*i+1].push_back(l);
        evt[2*i+1].push_back(r);
        evt[2*i+1].push_back(-1); // remove
    }

    sort(evt.begin(), evt.end());
    ll ans = 0, prev = 0;
    rep(i,0,2*n)
    {
        ans += (evt[i][0] - prev) * arr[0];
        update(evt[i][1], evt[i][2], 0, k, 0, evt[i][3]);
        prev = evt[i][0];
    }

    cout << b*h - ans << endl;
}

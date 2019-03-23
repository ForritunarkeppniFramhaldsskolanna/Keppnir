
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

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll b, h, n;
    cin >> b >> h >> n;

    vvi rect(2*n);
    rep(i,0,n)
    {
        ll x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        rect[2*i].push_back(x1);
        rect[2*i].push_back(1);
        rect[2*i].push_back(y1);
        rect[2*i].push_back(y2);
        rect[2*i+1].push_back(x2);
        rect[2*i+1].push_back(-1);
        rect[2*i+1].push_back(y1);
        rect[2*i+1].push_back(y2);
    }

    sort(rect.begin(), rect.end());

    ll ans = 0;
    ll pos = 0;
    ll in_column, row, cur;
    int at = 0;
    map<ll, ll> col;
    while(at < 2*n)
    {
        in_column = 0;
        row = 0;
        cur = 0;
        iter(it, col)
        {
            ll dist = it->first - row;
            if(cur == 0) in_column += dist;
            cur += it->second;
            row = it->first;
        }
        if(cur == 0) in_column += (h-row);
        ans += (rect[at][0] - pos)*in_column;
        //cout << "at: " << at << ", in_column: " << in_column << ", rect[at][0]: " << rect[at][0] << ". pos: " << pos << ", ans: " << ans << endl;
        pos = rect[at][0];
        int take = 1;
        while(at+take < n && rect[at][0] == rect[at+take][0])
        {
            take++;
        }
        rep(i, at, at+take)
        {
            col[rect[i][2]] += 1*rect[i][1];
            col[rect[i][3]] -= 1*rect[i][1];
        }
        at += take;
    }
    in_column = 0;
    row = 0;
    cur = 0;
    iter(it, col)
    {
        ll dist = it->first - row;
        if(cur == 0) in_column += dist;
        cur += it->second;
        row = it->first;
    }
    if(cur == 0) in_column += (h-row);
    ans += (b - pos)*in_column;

    cout << ans << endl;
    return 0;
}

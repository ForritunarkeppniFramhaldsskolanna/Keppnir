#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef complex<double> point;
template <class T> int size(const T &x) { return x.size(); }
const int INF = 2147483647;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int main() {
    int n;
    cin >> n;
    vector<point> pts(n);
    rep(i,0,n) {
        double x,y;
        cin >> x >> y;
        pts[i] = point(x,y);
    }

    ll end = clock() + 1 * CLOCKS_PER_SEC * 10 / 11;
    double mx = INFINITY;
    while (clock() < end) {
        random_shuffle(pts.begin(), pts.end());
        point at(0,0);
        double d = 0;
        rep(i,0,n) {
            d += abs(at - pts[i]);
            at = pts[i];
        }
        d += abs(at);
        mx = min(mx, d);
    }

    cout << setprecision(10) << fixed << mx << endl;

    return 0;
}


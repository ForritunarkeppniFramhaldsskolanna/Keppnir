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
    rep(i,0,n)  {
        double x, y;
        cin >> x >> y;
        pts[i] = point(x,y);
    }

    point at(0,0);
    double d = 0.0;
    while (size(pts) > 0) {
        int nxt = 0;
        rep(i,1,size(pts)) {
            if (abs(at - pts[nxt]) > abs(at - pts[i])) {
                nxt = i;
            }
        }
        d += abs(at - pts[nxt]);
        at = pts[nxt];
        swap(pts[nxt], pts[size(pts)-1]);
        pts.pop_back();
    }

    d += abs(at);
    cout << setprecision(10) << fixed << abs(d) << endl;

    return 0;
}


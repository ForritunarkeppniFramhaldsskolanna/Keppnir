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
    vector<point> pts;
    pts.push_back(point(0,0));
    bool allx0 = true;
    rep(i,0,n) {
        double x,y;
        cin >> x >> y;
        pts.push_back(point(x,y));
        allx0 = allx0 && abs(x) < 1e-9;
    }
    pts.push_back(point(0,0));

    double mn = INFINITY;
    if (allx0) {
        double l = 0,
               r = 0;
        rep(i,0,n) {
            l = min(l, pts[i+1].imag());
            r = max(r, pts[i+1].imag());
        }
        mn = 2*(r-l);
    } else {
        vi perm(size(pts));
        rep(i,0,size(pts)) perm[i] = i;
        do {
            double cur = 0.0;
            for (int i = 0; i < size(pts)-1; i++) {
                cur += abs(pts[perm[i+1]] - pts[perm[i]]);
            }
            mn = min(mn, cur);
        } while (next_permutation(perm.begin() + 1, perm.end() - 1));
    }

    cout << setprecision(10) << fixed << mn << endl;

    return 0;
}


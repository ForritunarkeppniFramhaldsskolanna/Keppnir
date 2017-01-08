#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
template <class T> int size(const T &x) { return x.size(); }
const int INF = 2147483647;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

vector<int> bits;
int tot = 0;

int dc(int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == r) {
        return tot + (bits[l] == 1 ? -1 : 1);
    }
    int m = (l+r)/2;
    int mx = max(dc(l, m), dc(m+1, r));

    int cur = 0, mxleft = -1;
    for (int i = m; i >= l; i--) {
        if (bits[i] == 1) {
            cur--;
        } else {
            cur++;
        }
        mxleft = max(mxleft, cur);
    }

    cur = 0;
    int mxright = -1;
    for (int i = m+1; i <= r; i++) {
        if (bits[i] == 1) {
            cur--;
        } else {
            cur++;
        }
        mxright = max(mxright, cur);
    }

    mx = max(mx, mxleft + mxright + tot);

    return mx;
}

int main() {
    int n;
    cin >> n;
    bits = vi(n);
    rep(i,0,n) {
        cin >> bits[i];
        tot += bits[i];
    }

    cout << dc(0,n-1) << endl;

    return 0;
}


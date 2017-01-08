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

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> names(n);
    rep(i,0,n) {
        cin >> names[i];
    }
    vector<int> sum(n);
    rep(i,0,m) {
        rep(j,0,n) {
            int pts;
            cin >> pts;
            sum[j] += pts;
        }
    }
    int mx = -1,
        mxi = -1;
    rep(i,0,n) {
        if (sum[i] > mx) {
            mx = sum[i];
            mxi = i;
        }
    }
    cout << names[mxi] << endl;
    return 0;
}


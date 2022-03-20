#include <bits/stdc++.h>
using namespace std;
//template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

int main() {
    int n, m;
    cin >> n >> m;

    vi arr(n);
    rep(i,0,n) {
        cin >> arr[i];
    }

    ll lo = 0,
       hi = 8000000000000000000LL,
       res = -1;

    while (lo <= hi) {
        ll cur = (lo+hi)/2;
        ll tot = 0;
        rep(i,0,n) {
            tot += cur / arr[i];
            if (tot >= m+1) {
                break;
            }
        }
        if (tot >= m+1) {
            res = cur;
            hi = cur - 1;
        } else {
            lo = cur + 1;
        }
    }

    assert(res != -1);
    cout << res << endl;

    return 0;
}


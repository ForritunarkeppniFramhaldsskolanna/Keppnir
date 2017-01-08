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
    int n, k;
    cin >> n >> k;

    vi perm(n);
    rep(i,0,n) {
        cin >> perm[i];
        perm[i]--;
    }

    /*
     * Simple O(n^2) solution. O(n) is also possible, but requires some extra
     * bookkeeping.
    */

    vi res(n);
    rep(i,0,n) {
        vi cyc;
        int at = i;
        do {
            cyc.push_back(at);
            at = perm[at];
        } while (at != i);
        res[i] = cyc[k % size(cyc)];
    }

    rep(i,0,n) {
        if (i != 0) {
            cout << " ";
        }
        cout << res[i]+1;
    }
    cout << endl;

    return 0;
}


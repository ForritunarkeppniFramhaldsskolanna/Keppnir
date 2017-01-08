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
    int mn = 0, mx = 0;
    int n;
    scanf("%d", &n);
    rep(i,0,n) {
        int x, y;
        scanf("%d %d", &x, &y);
        mn = min(mn, y);
        mx = max(mx, y);
    }

    cout << 2*abs(mn) + 2*abs(mx) << endl;

    return 0;
}


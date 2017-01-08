/*
 * This should work when all the T-shirts are of the same size.
 */
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
    scanf("%d", &n);
    m = n;
    vii need;
    rep(i,0,n) {
        int a, b;
        scanf("%d %d", &a, &b);
        need.push_back(ii(a,b));
    }
    int sz = -1,
        cnt = 0;
    rep(i,0,m) {
        int x;
        scanf("%d", &x);
        sz = x;
        cnt++;
    }
    bool ok = true;
    rep(i,0,size(need)) {
        if (need[i].first <= sz && sz <= need[i].second) {
            cnt--;
        } else {
            ok = false;
        }
    }
    if (ok && cnt >= 0) {
        printf("Jebb\n");
    } else {
        printf("Neibb\n");
    }
    return 0;
}


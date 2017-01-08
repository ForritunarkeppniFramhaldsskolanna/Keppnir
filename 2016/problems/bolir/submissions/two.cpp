/*
 * This should work when there are exactly two T-shirt sizes (1 and 2).
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
    vi one;
    int twocnt = 0;
    rep(i,0,n) {
        int a, b;
        scanf("%d %d", &a, &b);
        assert(b-a+1 <= 2);
        if (a == b) {
            one.push_back(a);
        } else if (a+1 == b) {
            twocnt++;
        } else {
            assert(false);
        }
    }
    map<int,int> cnt;
    rep(i,0,m) {
        int x;
        scanf("%d", &x);
        assert(1 <= x && x <= 2);
        cnt[x]++;
    }

    bool ok = true;
    rep(i,0,size(one)) {
        if (--cnt[one[i]] < 0) {
            ok = false;
        }
    }

    int sm = 0;
    iter(it,cnt) {
        sm += it->second;
    }
    ok = ok && sm >= twocnt;

    if (ok) {
        printf("Jebb\n");
    } else {
        printf("Neibb\n");
    }

    return 0;
}


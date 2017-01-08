/*
 * This should work when everyone wants a single T-shirt size.
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
    vi need;
    rep(i,0,n) {
        int a, b;
        scanf("%d %d", &a, &b);
        assert(a == b);
        need.push_back(a);
    }
    map<int,int> cnt;
    rep(i,0,m) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    bool ok = true;
    rep(i,0,size(need)) {
        if (--cnt[need[i]] < 0) {
            ok = false;
        }
    }
    if (ok) {
        printf("Jebb\n");
    } else {
        printf("Neibb\n");
    }
    return 0;
}


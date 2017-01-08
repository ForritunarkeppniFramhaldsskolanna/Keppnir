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
    vii arr(n);
    rep(i,0,n) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    vi sz(m);
    rep(i,0,m) {
        scanf("%d", &sz[i]);
    }
    sort(sz.begin(), sz.end());

    vector<bool> used(n, false);
    rep(i,0,m) {
        int mn = -1;
        rep(j,0,n) {
            if (!used[j] && arr[j].first <= sz[i] && sz[i] <= arr[j].second && (mn == -1 || arr[j].second < arr[mn].second)) {
                mn = j;
            }
        }
        if (mn != -1) {
            used[mn] = true;
        }
    }

    rep(i,0,n) {
        if (!used[i]) {
            printf("Neibb\n");
            return 0;
        }
    }
    printf("Jebb\n");

    return 0;
}


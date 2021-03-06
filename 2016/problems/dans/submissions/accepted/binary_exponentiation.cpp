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

vi apply(vi p, vi q) {
    int n = size(p);
    vi res(n);
    rep(i,0,n) {
        res[i] = p[q[i]];
    }
    return res;
}

vi mpow(vi a, int b) {
    int n = size(a);
    vi res(n);
    rep(i,0,n) res[i] = i;
    while (b) {
        if (b & 1) {
            res = apply(res,a);
        }
        a = apply(a,a);
        b >>= 1;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vi perm(n);
    rep(i,0,n) {
        cin >> perm[i];
        perm[i]--;
    }

    vi res = mpow(perm,k);

    rep(i,0,n) {
        if (i != 0) {
            cout << " ";
        }
        cout << res[i]+1;
    }
    cout << endl;

    return 0;
}


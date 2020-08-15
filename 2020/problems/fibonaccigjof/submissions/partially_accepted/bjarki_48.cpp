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

ll mod = 1000000007;

ll fibonacci(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 1;
    }

    ll a = 1,
       b = 1;
    for (int i = 1; i < n; i++) {
        a = (a + b) % mod;
        swap(a,b);
    }

    return a;
}

int main() {
    int n, m;
    cin >> n >> m;

    vi arr(n);
    rep(i,0,n) {
        cin >> arr[i];
    }

    rep(i,0,m) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, d;
            cin >> l >> r >> d;
            l--, r--;
            rep(i,l,r+1) {
                arr[i] += d;
            }
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int sm = 0;
            rep(i,l,r+1) {
                sm += fibonacci(arr[i]);
                sm %= mod;
            }
            cout << sm << endl;
        }
    }

    return 0;
}


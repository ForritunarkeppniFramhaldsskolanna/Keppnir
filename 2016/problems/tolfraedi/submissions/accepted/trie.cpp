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

struct node {
    node *down[2];
    int cnt;
    node() {
        memset(down, 0, sizeof(down));
        cnt = 0;
    }
};

int main() {
    int n;
    cin >> n;
    node *root = new node();
    ll sm = 0;
    rep(i,0,n) {
        char op;
        ll x;
        cin >> op >> x;
        int dx = op == 'A' ? 1 : -1;
        sm += x * dx;
        node *cur = root;
        for (int j = 60; j >= 0; j--) {
            cur->cnt += dx;
            int b = (x>>j)&1;
            if (!cur->down[b]) {
                cur->down[b] = new node();
            }
            cur = cur->down[b];
        }
        cur->cnt += dx;
        if (root->cnt == 0) {
            cout << "-1.000 -1.000 -1.000" << endl;
            continue;
        }
        ll mn = 0,
           mx = 0;
        node *mnat = root,
             *mxat = root;
        for (int j = 60; j >= 0; j--) {
            ll b = 1;
            if (mnat->down[0] && mnat->down[0]->cnt > 0) {
                b = 0;
            }
            mn |= b<<j;
            mnat = mnat->down[b];

            b = 0;
            if (mxat->down[1] && mxat->down[1]->cnt > 0) {
                b = 1;
            }
            mx |= b<<j;
            mxat = mxat->down[b];
        }

        cout << mn << " " << mx << " " << 1.0 * sm / root->cnt << endl;
    }

    return 0;
}


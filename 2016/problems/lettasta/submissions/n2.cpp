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
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int acnt = 0,
        bcnt = 0;
    rep(i,0,m) {
        int x, y;
        cin >> x >> y;
        acnt += x;
        bcnt += y;
    }
    if (acnt > bcnt) cout << a << endl;
    else cout << b << endl;
    return 0;
}


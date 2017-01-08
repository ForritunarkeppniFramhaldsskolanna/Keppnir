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
    vector<string> vs(n);
    int at = 0;
    rep(i,0,m) {
        vs[at] = vs[at] + "*";
        at = (at + 1) % n;
    }
    rep(i,0,n) {
        cout << vs[i] << endl;
    }
    return 0;
}


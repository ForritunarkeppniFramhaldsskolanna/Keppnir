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
    int n;
    cin >> n;
    vector<int> bits(n);
    int cnt = 0;
    rep(i,0,n) {
        cin >> bits[i];
        cnt += bits[i];
        bits[i] = bits[i] == 1 ? -1 : 1;
    }

    int cur = 0,
        mx = -1;
    rep(i,0,n) {
        cur = max(bits[i], cur + bits[i]);
        mx = max(mx, cur);
    }

    cout << cnt + mx << endl;

    return 0;
}


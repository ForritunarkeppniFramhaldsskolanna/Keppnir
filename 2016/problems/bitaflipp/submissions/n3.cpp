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
    rep(i,0,n) {
        cin >> bits[i];
    }

    int mx = 0;
    rep(i,0,n) {
        rep(j,i,n) {

            int cur = 0;
            rep(k,0,n) {
                if (i <= k && k <= j) {
                    cur += 1 - bits[k];
                } else {
                    cur += bits[k];
                }
            }

            mx = max(mx, cur);
        }
    }

    cout << mx << endl;

    return 0;
}


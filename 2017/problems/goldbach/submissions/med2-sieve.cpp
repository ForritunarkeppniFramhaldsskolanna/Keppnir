#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = 2147483647;

int main() {
    ll n;
    cin >> n;

    bool *prime = new bool[n+1];
    rep(i,0,n+1) prime[i] = i > 1;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            for (int j = i+i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    rep(a,1,n+1) {
        if (!prime[a]) continue;
        rep(b,1,n+1) {
            if (!prime[b]) continue;
            int c = n - a - b;
            if (prime[c]) {
                cout << a << " " << b << " " << c << endl;
                return 0;
            }
        }
    }

    cout << "Neibb" << endl;

    return 0;
}

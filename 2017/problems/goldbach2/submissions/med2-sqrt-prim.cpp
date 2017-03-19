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

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ll n;
    cin >> n;

    rep(a,1,n+1) {
        if (!is_prime(a)) continue;
        rep(b,1,n+1) {
            if (!is_prime(b)) continue;
            int c = n - a - b;
            if (is_prime(c)) {
                cout << a << " " << b << " " << c << endl;
                return 0;
            }
        }
    }

    cout << "Neibb" << endl;

    return 0;
}

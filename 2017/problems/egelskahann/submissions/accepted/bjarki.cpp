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

ll f(ll n) {
    if (n == 1) {
        return 1;
    }
    if (n % 2 == 0) {
        return f(n/2) * 2 - 1;
    }
    return f((n-1)/2) * 2 + 1;
}

int main() {
    ll n;
    cin >> n;
    cout << f(n) << endl;

    return 0;
}


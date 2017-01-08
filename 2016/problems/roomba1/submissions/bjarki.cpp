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
    if (n == 1 || m == 1) {
        cout << 2*n*m - 2 << endl;
    } else if (n % 2 == 0 || m % 2 == 0) {
        cout << n * m << endl;
    } else {
        cout << n * m + 1 << endl;
    }
    return 0;
}


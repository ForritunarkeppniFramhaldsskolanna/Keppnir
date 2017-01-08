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
    string a,b;
    cin >> a >> a;
    cin >> b >> b;

    if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}


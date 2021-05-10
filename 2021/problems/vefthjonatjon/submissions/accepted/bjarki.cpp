#include <bits/stdc++.h>
using namespace std;
//template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

int main() {
    int n;
    cin >> n;

    int a = 0, b = 0, c = 0;
    rep(i,0,n) {
        char p,q,r;
        cin >> p >> q >> r;
        if (p == 'J') a++;
        if (q == 'J') b++;
        if (r == 'J') c++;
    }

    cout << min(a,min(b,c)) << endl;

    return 0;
}


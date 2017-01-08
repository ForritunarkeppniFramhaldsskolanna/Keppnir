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
    string s;
    cin >> s;
    int n;
    cin >> n;
    int mx = 0;
    rep(i,0,n) {
        int t, x;
        string curs;
        cin >> t >> curs >> x;
        if (s == curs) {
            mx = max(mx, x);
        }
    }
    cout << mx << endl;
    return 0;
}


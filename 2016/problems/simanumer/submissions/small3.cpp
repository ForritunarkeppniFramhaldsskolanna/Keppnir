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
    vector<string> ss(n);
    rep(i,0,n) {
        cin >> ss[i];
    }
    int m;
    cin >> m;
    rep(i,0,m) {
        string s;
        cin >> s;
        int cnt = 0;
        rep(j,0,n) {
            if (s[0] == ss[j][0] && s[1] == ss[j][1] && s[2] == ss[j][2]) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}


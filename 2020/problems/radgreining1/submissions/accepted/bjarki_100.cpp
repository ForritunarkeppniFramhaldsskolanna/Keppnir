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
    int n, m;
    cin >> n >> m;
    vector<char> ans(n, '?');

    rep(i,0,m) {
        int start;
        string s;
        cin >> start >> s;
        start--;
        rep(j,0,s.size()) {
            int at = start + j;
            if (ans[at] != '?' && ans[at] != s[j]) {
                cout << "Villa" << endl;
                return 0;
            }
            ans[at] = s[j];
        }
    }

    rep(i,0,n) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}


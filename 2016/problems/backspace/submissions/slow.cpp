/*
 * Expected points: 60
 */
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
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    string s;
    cin >> s;

    string res = "";
    rep(i,0,size(s)) {
        if (s[i] == '<') {
            res = res.substr(0, size(res)-1);
        } else {
            res = res + s[i];
        }
    }
    cout << res << endl;

    return 0;
}


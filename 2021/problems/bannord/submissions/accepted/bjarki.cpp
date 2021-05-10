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
    string bad;
    cin >> bad;
    string s;
    while (cin >> s) {
        bool okay = true;
        iter(it,bad) {
            okay = okay && find(s.begin(), s.end(), *it) == s.end();
        }
        if (!okay) {
            rep(i,0,s.size()) {
                cout << "*";
            }
            cout << " ";
        } else {
            cout << s << " ";
        }
    }

    return 0;
}


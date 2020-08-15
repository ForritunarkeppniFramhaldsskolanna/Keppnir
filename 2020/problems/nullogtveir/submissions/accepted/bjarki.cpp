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

string s;
ll mem[60][2];

ll count(int at, bool same) {
    if (at == s.size()) {
        return 1;
    }
    if (mem[at][same] != -1) {
        return mem[at][same];
    }
    ll res = 0;
    for (int d = 0; d <= 2; d += 2) {
        if (same && d > s[at] - '0') {
            continue;
        }
        res += count(at+1, same && d == s[at] - '0');
    }
    return mem[at][same] = res;
}

int main() {
    memset(mem,-1,sizeof(mem));
    cin >> s;
    cout << count(0,true) << endl;

    return 0;
}


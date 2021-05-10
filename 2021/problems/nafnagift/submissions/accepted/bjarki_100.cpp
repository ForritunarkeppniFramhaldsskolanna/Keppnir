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

int mem[1010][1010];

string a, b;
int dp(int l, int r) {
    if (l == a.size() && r == b.size()) {
        return 0;
    }
    if (mem[l][r] != -1) {
        return mem[l][r];
    }
    int mn = INF;
    if (l < a.size()) {
        mn = min(mn, 1 + dp(l+1, r));
    }
    if (r < b.size()) {
        mn = min(mn, 1 + dp(l, r+1));
    }
    if (l < a.size() && r < b.size() && a[l] == b[r]) {
        mn = min(mn, 1 + dp(l+1, r+1));
    }
    return mem[l][r] = mn;
}

void rec(int l, int r) {
    if (l == a.size() && r == b.size()) {
        return;
    }
    int mn = dp(l,r);
    if (l < a.size() && mn == 1 + dp(l+1, r)) {
        cout << a[l];
        rec(l+1, r);
        return;
    }
    if (r < b.size() && mn == 1 + dp(l, r+1)) {
        cout << b[r];
        rec(l, r+1);
        return;
    }
    cout << a[l];
    rec(l+1, r+1);
}

int main() {
    memset(mem,-1,sizeof(mem));
    cin >> a >> b;

    dp(0,0);
    rec(0,0);
    cout << endl;

    return 0;
}


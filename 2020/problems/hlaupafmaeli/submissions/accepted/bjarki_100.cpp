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

long long cnt(long long y) {
    return y/4 - y/100 + y/400;
}

int main() {
    long long year;
    cin >> year;

    long long ans = cnt(year) - cnt(2020);

    if (cnt(year) == cnt(year-1)) {
        cout << "Neibb" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}


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
    int n, p;
    cin >> n >> p;

    set<int> found[4];
    int mn = INF;
    rep(card,0,n) {
        int x, y;
        cin >> x >> y;
        x--;
        found[x].insert(y);
        for (int start = y-2; start <= y; start++) {
            bool all = true;
            rep(i,0,3) {
                all = all && found[x].find(start+i) != found[x].end();
            }
            if (all) {
                mn = min(mn, card);
            }
        }
    }

    if (mn == INF) {
        cout << "Neibb" << endl;
    } else {
        cout << max(0, mn - p + 1) << endl;
    }

    return 0;
}


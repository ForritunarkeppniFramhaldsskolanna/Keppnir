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

char arr[510][510];

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,0,n) {
        rep(j,0,m) { 
            cin >> arr[i][j];
        }
    }

    int qs;
    cin >> qs;
    rep(q,0,qs) {
        int x, y, k;
        cin >> x >> y >> k;
        x--, y--;
        while (k--) {
            if (arr[x][y] == 'v') {
                x++;
            } else if (arr[x][y] == '<') {
                y--;
            } else if (arr[x][y] == '^') {
                x--;
            } else {
                y++;
            }
        }
        cout << x+1 << " " << y+1 << endl;
    }

    return 0;
}


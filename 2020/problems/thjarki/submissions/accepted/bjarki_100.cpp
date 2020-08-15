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
ii jmp[510][510][31];

int main() {
    int n, m;
    cin >> n >> m;

    rep(i,0,n) {
        rep(j,0,m) {
            cin >> arr[i][j];
            switch (arr[i][j]) {
                case '<': jmp[i][j][0] = ii(i,j-1); break;
                case '>': jmp[i][j][0] = ii(i,j+1); break;
                case '^': jmp[i][j][0] = ii(i-1,j); break;
                case 'v': jmp[i][j][0] = ii(i+1,j); break;
            }
        }
    }

    rep(k,1,31) {
        rep(i,0,n) {
            rep(j,0,m) {
                ii nxt = jmp[i][j][k-1];
                jmp[i][j][k] = jmp[nxt.first][nxt.second][k-1];
            }
        }
    }

    int qs;
    cin >> qs;
    rep(q,0,qs) {
        int x, y, k;
        cin >> x >> y >> k;
        x--, y--;

        for (int i = 30; i >= 0; i--) {
            if (k & (1<<i)) {
                ii nxt = jmp[x][y][i];
                x = nxt.first;
                y = nxt.second;
            }
        }

        cout << x+1 << " " << y+1 << endl;
    }

    return 0;
}


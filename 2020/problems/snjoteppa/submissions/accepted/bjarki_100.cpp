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

char arr[2][1000000];

#define BLOCK(i,j) (0 <= (j) && (j) < n && arr[i][j] == 'o')

int main() {
    int n, k;
    cin >> n >> k;

    rep(i,0,2) {
        rep(j,0,n) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    rep(i,0,2) {
        rep(j,0,n) {
            cnt += BLOCK(i,j) && BLOCK(i^1,j-1);
            cnt += BLOCK(i,j) && BLOCK(i^1,j);
            cnt += BLOCK(i,j) && BLOCK(i^1,j+1);
        }
    }

    rep(j,0,k) {
        char op;
        cin >> op;
        if (op == 'U') {
            int x,y;
            cin >> x >> y;
            x--, y--;

            cnt -= BLOCK(x,y) && BLOCK(x^1,y-1);
            cnt -= BLOCK(x,y) && BLOCK(x^1,y);
            cnt -= BLOCK(x,y) && BLOCK(x^1,y+1);

            if (arr[x][y] == 'o') {
                arr[x][y] = '.';
            } else {
                arr[x][y] = 'o';
            }

            cnt += BLOCK(x,y) && BLOCK(x^1,y-1);
            cnt += BLOCK(x,y) && BLOCK(x^1,y);
            cnt += BLOCK(x,y) && BLOCK(x^1,y+1);

        } else {
            if (cnt == 0) {
                cout << "Jebb" << endl;
            } else {
                cout << "Neibb" << endl;
            }
        }
    }

    return 0;
}


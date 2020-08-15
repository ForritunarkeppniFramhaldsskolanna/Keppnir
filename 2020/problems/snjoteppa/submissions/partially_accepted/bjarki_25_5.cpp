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

int main() {
    int n, k;
    cin >> n >> k;

    rep(i,0,2) {
        rep(j,0,n) {
            cin >> arr[i][j];
        }
    }

    rep(q,0,k) {
        char op;
        cin >> op;
        if (op == 'U') {
            int x, y;
            cin >> x >> y;
            x--, y--;
            if (arr[x][y] == 'o') {
                arr[x][y] = '.';
            } else {
                arr[x][y] = 'o';
            }
        } else {
            bool ok = true;
            rep(i,0,n) {
                if (arr[0][i] == 'o' && arr[1][i] == 'o') {
                    ok = false;
                }
            }
            rep(i,0,n-1) {
                if (arr[0][i] == 'o' && arr[1][i+1] == 'o') {
                    ok = false;
                }
                if (arr[1][i] == 'o' && arr[0][i+1] == 'o') {
                    ok = false;
                }
            }
            if (ok) {
                cout << "Jebb" << endl;
            } else {
                cout << "Neibb" << endl;
            }
        }
    }

    return 0;
}


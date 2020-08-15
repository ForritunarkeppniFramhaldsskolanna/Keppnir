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

    int n, m;
    cin >> n >> m;

    vector<vi> arr(n, vi(m));

    rep(i,0,n) {
        rep(j,0,m) {
            cin >> arr[i][j];
        }
    }

    rep(i,1,n-1) {
        rep(j,1,m-1) {

            bool laegd = true;
            rep(di,-1,2) {
                rep(dj,-1,2) {
                    if (abs(di)+abs(dj) != 1) {
                        continue;
                    }
                    if (arr[i+di][j+dj] < arr[i][j]) {
                        laegd = false;
                    }
                }
            }

            if (laegd) {
                cout << "Jebb" << endl;
                return 0;
            }
        }
    }

    cout << "Neibb" << endl;

    return 0;
}


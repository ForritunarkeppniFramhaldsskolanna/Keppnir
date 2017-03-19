#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = 2147483647;

bool anyone[510][510];
bool have[2000];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    memset(anyone,0,sizeof(anyone));
    memset(have,0,sizeof(have));
    rep(i,0,k) {
        int x,y;
        cin >> x >> y;
        x--, y--;
        anyone[x][y] = true;
    }
    rep(i,0,n) {
        rep(j,0,m) {
            if (anyone[i][j]) {
                have[i-j + 1000] = true;
            }
        }
    }
    int cnt = 0;
    rep(i,0,2000) cnt += have[i];
    cout << cnt << endl;

    return 0;
}


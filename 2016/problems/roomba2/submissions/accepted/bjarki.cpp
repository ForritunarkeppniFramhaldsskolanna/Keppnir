#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
template <class T> int size(const T &x) { return x.size(); }
const int INF = 2147483647;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

vii res;
int signum(int x) {
    return x > 0 ? 1 : x < 0 ? -1 : 0;
}

void line(int x1, int y1, int x2, int y2) {
    int dx = signum(x2-x1),
        dy = signum(y2-y1);
    while (true) {
        res.push_back(ii(x1,y1));
        if (x1 == x2 && y1 == y2) {
            break;
        }
        x1 += dx;
        y1 += dy;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    bool sw = false;
    if (n == 1 && m == 1) {
        cout << "0 0" << endl;
        return 0;
    }
    if (m == 1) {
        sw = true;
        swap(n,m);
    }
    if (n == 1) {
        line(0, 0, 0, m-1);
        line(0, m-2, 0, 0);
    } else {
        if (m % 2 == 0) {
            sw = true;
            swap(n,m);
        }
        if (n % 2 == 0) {
            line(0,0,0,0);
            for (int i = 0; i < n; i += 2) {
                line(i, 1, i, m-1);
                line(i+1, m-1, i+1, 1);
            }
            line(n-1,0,0,0);
        } else {
            // both odd
            line(0,0,0,0);
            for (int i = 0; i < n-2; i += 2) {
                line(i, 1, i, m-1);
                if (i+1 < n-2) {
                    line(i+1, m-1, i+1, 1);
                }
            }
            for (int j = m-1; j >= 0; j -= 2) {
                line(n-2, j, n-1, j);
                if (j-1 >= 0) {
                    line(n-1, j-1, n-2, j-1);
                }
            }
            line(n-2, 0, 0,0);
        }
    }
    if (sw) {
        rep(i,0,size(res)) {
            swap(res[i].first, res[i].second);
        }
    }
    rep(i,0,size(res)) {
        printf("%d %d\n", res[i].first, res[i].second);
    }
    return 0;
}


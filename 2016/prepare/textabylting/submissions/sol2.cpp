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

int main() {
    string line;
    int n;
    getline(cin, line);
    n = atoi(line.c_str());
    vector<string> lines(n);
    int mx = 0;
    rep(i,0,n) {
        getline(cin, lines[i]);
        mx = max(mx, size(lines[i]));
    }
    rep(i,0,mx) {
        rep(j,0,n) {
            if (i < size(lines[j])) {
                printf("%c", lines[j][i]);
            }
        }
        printf("\n");
    }
    return 0;
}


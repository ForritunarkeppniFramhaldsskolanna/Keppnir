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

int arr[100100];
int jmp[20][100100];

int main() {
    int n, m;
    cin >> n >> m;

    rep(i,0,n) {
        cin >> arr[i];
    }
    for (int i = n-1; i >= 0; i--) {
        jmp[0][i] = i+1;
        while (jmp[0][i] < n && arr[jmp[0][i]] < arr[i]) {
            jmp[0][i] = jmp[0][jmp[0][i]];
        }
    }
    rep(j,1,20) {
        rep(i,0,n) {
            int dest = jmp[j-1][i];
            if (dest < n) {
                dest = jmp[j-1][dest];
            }
            jmp[j][i] = dest;
        }
    }

    rep(it,0,m) {
        int s, d;
        cin >> s >> d;
        s--;

        for (int i = 19; i >= 0 && s < n; i--) {
            if (d & (1<<i)) {
                s = jmp[i][s];
            }
        }
        if (s < n) {
            cout << s+1 << endl;
        } else {
            cout << "leik lokid" << endl;
        }
    }

    return 0;
}


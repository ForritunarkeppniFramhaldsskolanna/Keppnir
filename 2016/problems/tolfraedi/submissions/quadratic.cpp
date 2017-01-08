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

int arr[100000];

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    rep(i,0,n) {
        char c;
        int x;
        cin >> c >> x;
        if (c == 'A') {
            arr[cnt++] = x;
        } else {
            int at = 0;
            while (arr[at] != x) {
                at++;
            }
            arr[at] = arr[cnt-1];
            cnt--;
        }
        int mn = -1,
            mx = -1;
        ll sm = 0;
        rep(j,0,cnt) {
            if (mn == -1 || arr[j] < mn) {
                mn = arr[j];
            }
            if (mx == -1 || arr[j] > mx) {
                mx = arr[j];
            }
            sm += arr[j];
        }
        if (mn == -1) {
            cout << "-1 -1 -1" << endl;
        } else {
            cout << setprecision(20) << fixed << mn << " " << mx << " " << static_cast<double>(sm) / cnt << endl;
        }
    }
    return 0;
}


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
    int arr[1000];
    memset(arr, 0, sizeof(arr));
    int n;
    cin >> n;
    rep(i,0,n) {
        string s;
        cin >> s;
        arr[((s[0]-'0')*10 + (s[1]-'0')) * 10 + s[2] - '0']++;
    }

    int qs;
    cin >> qs;
    rep(i,0,qs) {
        int x;
        cin >> x;
        cout << arr[x] << endl;
    }

    return 0;
}


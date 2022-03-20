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
    srand(13337);
    int n;
    cin >> n;
    vector<string> arr(n);
    rep(i,0,n) {
        cin >> arr[i];
    }
    rep(i,0,n) {
        cout << arr[i] << endl;
        string s;
        cin >> s;
        if (s == "OOOOO") {
            break;
        }
    }
    return 0;
}


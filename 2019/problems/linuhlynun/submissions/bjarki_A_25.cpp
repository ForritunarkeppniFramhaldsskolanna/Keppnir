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
    int n;
    cin >> n;

    vii arr(n);

    rep(i,0,n) {
        cin >> arr[i].first >> arr[i].second;
    }

    ll best = -1;
    int besti = -1;

    rep(i,0,n) {
        ll cur = 0;
        rep(j,0,n) {
            cur += (ll)abs(arr[i].first - arr[j].first) * arr[j].second;
        }
        if (besti == -1 || cur < best || (cur == best && arr[i].first < besti)) {
            besti = arr[i].first;
            best = cur;
        }
    }

    cout << besti << endl;

    return 0;
}


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
    vector<ll> arr(n);
    rep(i,0,n) cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll ans = 0;
    rep(i,0,n-1) {
        ans += (arr[i+1]-arr[i])*(arr[i+1]-arr[i]);
    }
    cout << ans << endl;

    return 0;
}


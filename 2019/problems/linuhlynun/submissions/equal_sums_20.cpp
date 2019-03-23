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

    ll right = 0, left = 0;
    rep(i,0,n) {
        cin >> arr[i].first >> arr[i].second;
        right += arr[i].second;
    }

    sort(arr.begin(), arr.end());


    int ans = -1;
    rep(i,0,n) {
        right -= arr[i].second;
        if (left <= right) {
            ans = arr[i].first;
            if (left == right) {
                break;
            }
        }
        left += arr[i].second;
    }

    cout << ans << endl;

    return 0;
}


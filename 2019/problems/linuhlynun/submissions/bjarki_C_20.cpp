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

    vi arr(n);

    rep(i,0,n) {
        int bla;
        cin >> arr[i] >> bla;
    }

    sort(arr.begin(), arr.end());

    int at = arr[0];
    ll cur = 0;
    int left = 0, right = 0;
    rep(i,0,n) {
        cur += (ll)abs(at - arr[i]);
        right++;
    }

    ll best = -1;
    int besti = -1;

    rep(i,0,n) {
        cur += (ll)abs(at - arr[i]) * left;
        cur -= (ll)abs(at - arr[i]) * right;
        at = arr[i];

        left++;
        right--;

        if (besti == -1 || cur < best) {
            best = cur;
            besti = arr[i];
        }
    }

    cout << besti << endl;

    return 0;
}


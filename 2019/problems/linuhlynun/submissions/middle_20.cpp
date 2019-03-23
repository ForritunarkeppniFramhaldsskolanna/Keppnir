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

    sort(arr.begin(), arr.end());

    cout << arr[(arr.size() - 1) / 2].first << endl;

    return 0;
}


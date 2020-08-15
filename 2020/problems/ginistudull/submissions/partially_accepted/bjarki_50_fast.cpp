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

    vector<double> arr(n);
    double sm2 = 0.0;
    rep(i,0,n) {
        cin >> arr[i];
        sm2 += arr[i];
    }
    sort(arr.begin(), arr.end());

    double sm1 = 0.0;
    rep(i,0,n) {
        rep(j,i+1,n) {
            sm1 += arr[j] - arr[i];
        }
    }

    cout << setprecision(10) << fixed << sm1 / (n * sm2) << endl;

    return 0;
}


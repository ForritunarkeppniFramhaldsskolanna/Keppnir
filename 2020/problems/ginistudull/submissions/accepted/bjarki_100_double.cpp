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
    double sm = 0.0;
    rep(i,0,n) {
        cin >> arr[i];
        sm += arr[i];
    }

    sort(arr.begin(), arr.end());

    double sm1 = 0.0,
           sm2 = 0.0,
           pref = 0.0;
    rep(i,0,n) {
        double left = pref,
               right = sm - arr[i] - pref;

        sm1 += i * arr[i] - left;
        sm1 += right - (n - i - 1) * arr[i];

        pref += arr[i];
    }

    rep(i,0,n) {
        sm2 += n * arr[i];
    }

    cout << setprecision(10) << fixed << sm1 / (2*sm2) << endl;

    return 0;
}


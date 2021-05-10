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
        cin >> arr[i];
    }
    // sort(arr.begin(), arr.end());
    do {
        bool ok = true;
        rep(i,0,n-1) {
            if (gcd(arr[i], arr[i+1]) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            iter(it,arr) {
                cout << endl;
                cout << "       " << *it << "     ";
            }
            return 0;
        }
    } while (next_permutation(arr.begin(), arr.end()));

    cout << "Neibb" << endl;
    return 0;
}


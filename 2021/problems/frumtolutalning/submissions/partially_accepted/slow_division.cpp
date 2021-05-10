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
    ll a, b;
    cin >> a >> b;
    ll cnt = 0;
    for (ll i = a; i <= b; i++) {
        bool prime = true;
        for (ll j = 2; j < i; j++) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime && i != 1) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}


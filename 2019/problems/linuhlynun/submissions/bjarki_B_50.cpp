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

    vector<ll> sm(1001);

    rep(i,0,n) {
        int x, c;
        cin >> x >> c;
        sm[x] += c;
    }

    ll best = -1;
    int besti = -1;
    rep(i,1,1001) {
        ll cur = 0;
        rep(j,0,1001) {
            cur += (ll)abs(i-j) * sm[j];
        }
        if (besti == -1 || cur < best) {
            best = cur;
            besti = i;
        }
    }

    cout << besti << endl;

    return 0;
}


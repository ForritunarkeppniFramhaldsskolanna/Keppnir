#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
template <class T> int size(const T &x) { return x.size(); }
const int INF = 2147483647;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

bool is_palindrome(ll n) {
    vector<ll> digs;
    while (n != 0) {
        digs.push_back(n % 10);
        n /= 10;
    }
    rep(i,0,size(digs)) {
        if (digs[i] != digs[size(digs)-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    ll bound = 1;
    for (int i = 1; i <= 43; i++) {
        bound = bound * 2;
        ll at = bound;
        while (!is_palindrome(at)) at--;
        cout << i << " " << at << endl;
    }

    return 0;
}

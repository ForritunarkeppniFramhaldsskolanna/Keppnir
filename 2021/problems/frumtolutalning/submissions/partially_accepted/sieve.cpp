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
    bool *prime = new bool[b+1];
    prime[1] = false;
    for (ll i = 2; i <= b; i++) prime[i] = true;
    for (ll i = 2; i <= b; i++) {
        if (prime[i]) {
            for (ll j = i+i; j <= b; j += i) {
                prime[j] = false;
            }
        }
    }
    ll cnt = 0;
    for (ll i = a; i <= b; i++) {
        if (prime[i]) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}


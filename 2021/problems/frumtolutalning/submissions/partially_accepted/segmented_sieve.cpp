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

    ll st = 1;
    while (st*st <= b) st++;

    bool *prime = new bool[st+1];
    prime[1] = false;
    for (ll i = 1; i <= st; i++) prime[i] = true;
    for (ll i = 2; i <= st; i++) {
        if (prime[i]) {
            for (ll j = i+i; j <= st; j += i) {
                prime[j] = false;
            }
        }
    }

    vector<ll> primes;
    for (ll i = 2; i <= st; i++) {
        if (prime[i]) {
            primes.push_back(i);
        }
    }

    prime = new bool[b-a+1];
    for (ll i = a; i <= b; i++) prime[i-a] = true;

    iter(it,primes) {
        for (ll i = (a+*it-1)/(*it)*(*it); i <= b; i += *it) {
            if (i != *it) {
                prime[i-a] = false;
            }
        }
    }

    ll cnt = 0;
    for (ll i = a; i <= b; i++) {
        if (prime[i-a] && i != 1) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}


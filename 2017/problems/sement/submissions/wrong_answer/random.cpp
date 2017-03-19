#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = 2147483647;

int main() {
    int n;
    long long s;
    cin >> n >> s;
    vector<ll> arr(n);
    rep(i,0,n) {
        cin >> arr[i];
    }
    int it = 1000000000/n;
    rep(i,0,it) {
        int a = rand() % n,
            b = rand() % n;
        if (a == b) continue;
        if (arr[a] + arr[b] == s) {
            cout << a << " " << b << endl;
            return 0;
        }
    }
    cout << "Neibb" << endl;
    return 0;
}


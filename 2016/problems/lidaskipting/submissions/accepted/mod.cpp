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

int main() {
    string s;
    cin >> s;
    int x = 0;
    rep(i,0,size(s)) {
        x = x * 10 + (s[i] - '0');
        x %= 3;
    }
    if (x == 0) {
        cout << "Jebb" << endl;
    } else {
        cout << "Neibb" << endl;
    }
    return 0;
}


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
    string s;
    cin >> s;
    bool ok = s[0] == 'b';
    rep(i,1,size(s)-2) {
        ok = ok && s[i] == 'r';
    }

    cout << (ok ? "Jebb" : "Neibb") << endl;

    return 0;
}


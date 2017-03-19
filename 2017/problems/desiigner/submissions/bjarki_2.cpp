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

bool is_serh(char c) {
    if (c == 'a') return true;
    if (c == 'e') return true;
    if (c == 'i') return true;
    if (c == 'o') return true;
    if (c == 'u') return true;
    if (c == 'y') return true;
    return false;
}

int main() {
    string s;
    cin >> s;
    bool ok = s[0] == 'b';
    rep(i,1,size(s)-2) {
        ok = ok && s[i] == 'r';
    }
    ok = ok && is_serh(s.back());

    cout << (ok ? "Jebb" : "Neibb") << endl;

    return 0;
}


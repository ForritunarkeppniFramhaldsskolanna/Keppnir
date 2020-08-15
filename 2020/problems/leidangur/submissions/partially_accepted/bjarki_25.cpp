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
    string s;
    cin >> s;

    int p = 0,
        g = 0,
        o = 0;
    iter(it,s) {
        switch (*it) {
            case 'p': p++; break;
            case 'g': g++; break;
            case 'o': o++; break;
        }
    }

    cout << p << endl;
    cout << g << endl;
    cout << o << endl;

    return 0;
}


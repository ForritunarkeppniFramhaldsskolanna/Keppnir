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
    ll cnt = 0, right = 0;
    iter(it,s) {
        if (*it == '>') {
            right++;
        } else if (*it == '<') {
            cnt += right;
        }
    }
    cout << cnt << endl;
    return 0;
}


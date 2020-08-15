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

    int best = -1;
    string ans;

    rep(i,0,n) {
        int num;
        string s;
        cin >> s >> num;
        if (num > best) {
            best = num;
            ans = s;
        }
    }

    assert(best != -1);
    cout << ans << endl;

    return 0;
}


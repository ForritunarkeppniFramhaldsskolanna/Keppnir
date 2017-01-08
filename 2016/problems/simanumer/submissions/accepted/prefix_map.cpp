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
    int n;
    cin >> n;
    map<string,int> cnt;
    rep(i,0,n) {
        string s;
        cin >> s;
        rep(j,0,size(s)+1) {
            cnt[s.substr(0,j)]++;
        }
    }

    int qs;
    cin >> qs;
    rep(q,0,qs) {
        string s;
        cin >> s;
        cout << cnt[s] << endl;
    }

    return 0;
}


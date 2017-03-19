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
    vector<int> found;
    int n, m, k;
    cin >> n >> m >> k;
    rep(i,0,k) {
        int a,b;
        cin >> a >> b;
        bool f = false;
        iter(it,found) {
            if (*it == a-b) {
                f = true;
                break;
            }
        }
        if (!f) {
            found.push_back(a-b);
        }
    }
    cout << size(found) << endl;

    return 0;
}


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
    string best = "";
    rep(i,0,n) {
        string word;
        cin >> word;
        if (word.size() < 5) continue;
        int found = 0;
        bool ok = true;
        iter(it,word) {
            int cur = 1<<(*it - 'a');
            if (found & cur) {
                ok = false;
            }
            found |= cur;
        }
        if (!ok) continue;
        if (best == "" || word.size() < best.size() || (word.size() == best.size() && word > best)) {
            best = word;
        }
    }

    if (best == "") {
        cout << "Neibb" << endl;
    } else {
        cout << best << endl;
    }

    return 0;
}


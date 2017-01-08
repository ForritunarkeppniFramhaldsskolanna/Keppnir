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

struct trie {
    trie *down[10];
    int cnt;
    trie() {
        memset(down, 0, sizeof(down));
        cnt = 0;
    }
};

int main() {
    int n;
    cin >> n;
    trie *root = new trie();
    rep(i,0,n) {
        string s;
        cin >> s;
        trie *cur = root;
        rep(j,0,size(s)) {
            cur->cnt++;
            int x = s[j] - '0';
            if (!cur->down[x]) {
                cur->down[x] = new trie();
            }
            cur = cur->down[x];
        }
        cur->cnt++;
    }

    int qs;
    cin >> qs;
    rep(q,0,qs) {
        string s;
        cin >> s;
        trie *cur = root;
        rep(j,0,size(s)) {
            if (!cur) break;
            cur = cur->down[s[j] - '0'];
        }
        if (cur) {
            cout << cur->cnt << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}


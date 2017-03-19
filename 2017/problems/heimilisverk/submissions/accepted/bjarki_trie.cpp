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

struct trie {
    map<char, trie*> down;
    bool end;
    trie() {
        end = false;
    }
};

int main() {
    string line;
    getline(cin,line);
    int n = atoi(line.c_str());
    set<string> res;
    trie *root = new trie();

    rep(i,0,n) {
        getline(cin,line);
        trie *cur = root;
        iter(it,line) {
            char c = *it;
            if (cur->down.find(c) == cur->down.end()) {
                cur->down[c] = new trie();
            }
            cur = cur->down[c];
        }
        if (!cur->end) {
            cur->end = true;
            cout << line << endl;
        }
    }
    return 0;
}


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

unordered_set<string> valid;
string start, last;
int n, m;

unordered_set<string> inpath;
vector<string> path;
void bt(string cur, int maxdepth) {
    if (inpath.find(cur) != inpath.end()) {
        return;
    }
    inpath.insert(cur);
    path.push_back(cur);

    if (cur == last) {
        cout << (int)path.size()-1 << endl;
        iter(it,path) {
            cout << *it << endl;
        }
        exit(0);
    }

    if (maxdepth > 0) {
        rep(i,0,n) {
            for (int d = -1; d <= 1; d += 2) {
                int curd = cur[i] - '0';
                curd = ((curd + d) % 10 + 10) % 10;
                string nxt = cur;
                nxt[i] = curd + '0';
                if (valid.find(nxt) != valid.end()) {
                    bt(nxt, maxdepth-1);
                }
            }
        }
    }

    path.pop_back();
    inpath.erase(cur);
}

int main() {
    cin >> n >> m;
    cin >> start >> last;
    valid.insert(start);
    valid.insert(last);
    rep(i,0,m) {
        string s;
        cin >> s;
        valid.insert(s);
    }
    for (int maxdepth = 0; maxdepth <= m+2; maxdepth++) {
        bt(start, maxdepth);
    }
    cout << "Neibb" << endl;

    return 0;
}


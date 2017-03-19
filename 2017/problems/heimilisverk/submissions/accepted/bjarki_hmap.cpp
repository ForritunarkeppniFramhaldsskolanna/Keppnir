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
    string line;
    getline(cin,line);
    int n = atoi(line.c_str());
    unordered_set<string> res;
    rep(i,0,n) {
        getline(cin,line);
        if (res.find(line) == res.end()) {
            res.insert(line);
            cout << line << endl;
        }
    }
    return 0;
}


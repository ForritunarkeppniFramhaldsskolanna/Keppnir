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

bool leq(vi a, vi b) {
    return a[0] <= b[0] &&
        a[1] <= b[1] && 
        a[2] <= b[2];
}

vi best(vi a, vi b) {
    if (a.size() == 0) return b;
    if (b.size() == 0) return a;

    if (a == b) {
        return a;
    }

    if (leq(a,b)) {
        assert(!leq(b,a));
        return b;
    }

    assert(leq(b,a));
    return a;
}

string s;
map<pair<int,vector<char> >, vi> mem;
vi dp(int at, vector<char> S) {
    if (at == s.size()) {
        int p = 0,
            g = 0,
            o = 0;
        iter(it,S) {
            switch (*it) {
                case 'p': p++; break;
                case 'g': g++; break;
                case 'o': o++; break;
            }
        }
        return {p,g,o};
    }

    pair<int, vector<char> > st(at, S);
    if (mem.find(st) != mem.end()) {
        return mem[st];
    }

    if (s[at] == '.') {
        return mem[st] = dp(at+1, S);
    }

    if (isupper(s[at])) {
        while (!S.empty() && S.back() != tolower(s[at])) {
            S.pop_back();
        }
        if (S.empty()) {
            return vi();
        }
        S.pop_back();
        return mem[st] = dp(at+1, S);
    }

    vi res = dp(at+1, S);
    S.push_back(s[at]);
    return mem[st] = best(res, dp(at+1, S));
}

int main() {
    cin >> s;

    vi res = dp(0, vector<char>());
    if (res.empty()) {
        cout << "Neibb" << endl;
        return 0;
    }

    rep(i,0,3) {
        cout << res[i] << endl;
    }

    return 0;
}


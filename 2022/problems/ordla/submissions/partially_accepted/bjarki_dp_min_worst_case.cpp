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

vector<string> words;
int n;

#define MAXN 500

struct constraints {
    map<int,char> known_correct;
    map<int,char> known_incorrect;
    map<char,int> atleast;
    set<char> exact;
} cons[MAXN][MAXN];

bool is_cons[MAXN][MAXN][MAXN];

constraints derive_constraints(string word, string correct) {
    constraints res;
    map<char,int> a, b;
    rep(i,0,(int)word.size()) {
        a[word[i]]++;
        b[correct[i]]++;
        if (word[i] == correct[i]) {
            res.known_correct[i] = word[i];
        } else {
            res.known_incorrect[i] = word[i];
        }
    }
    iter(it,a) {
        res.atleast[it->first] = min(it->second, b[it->first]);
        if (it->second > b[it->first]) {
            res.exact.insert(it->first);
        }
    }
    return res;
}

bool is_consistent(string word, constraints con) {
    iter(it,con.known_correct) {
        if (word[it->first] != it->second) {
            return false;
        }
    }
    iter(it,con.known_incorrect) {
        if (word[it->first] == it->second) {
            return false;
        }
    }
    map<char,int> cnt;
    iter(it,word) {
        cnt[*it]++;
    }
    iter(it,con.atleast) {
        if (cnt[it->first] < it->second) {
            return false;
        }
        if (con.exact.find(it->first) != con.exact.end()) {
            if (cnt[it->first] > it->second) {
                return false;
            }
        }
    }
    return true;
}

struct myhash {
    size_t operator ()(const vi &arr) const {
        size_t res = 27;
        iter(it,arr) {
            res = res * 31 + *it;
        }
        return res;
    }
};

unordered_map<vi, int, myhash> mem;
int dp(vi rem) {
    if (mem.find(rem) != mem.end()) {
        return mem[rem];
    }
    int mn = INF;
    iter(nxt,rem) {
        int mx = 0;
        iter(correct,rem) {
            if (*nxt == *correct) {
                mx = max(mx, 1);
            } else {
                vi consistent;
                iter(poss,rem) {
                    if (is_cons[*nxt][*correct][*poss]) {
                        consistent.push_back(*poss);
                    }
                }
                mx = max(mx, 1 + dp(consistent));
            }
        }
        mn = min(mn, mx);
    }
    return mem[rem] = mn;
}

void rec(vi rem) {
    iter(nxt,rem) {
        int mx = 0;
        iter(correct,rem) {
            if (*nxt == *correct) {
                mx = max(mx, 1);
            } else {
                vi consistent;
                iter(poss,rem) {
                    if (is_cons[*nxt][*correct][*poss]) {
                        consistent.push_back(*poss);
                    }
                }
                mx = max(mx, 1 + dp(consistent));
            }
        }
        if (mx == dp(rem)) {
            cout << words[*nxt] << endl;

            string pattern;
            cin >> pattern;

            constraints con;

            bool correct = true;
            rep(i,0,pattern.size()) {
                if (pattern[i] == 'O') {
                    con.known_correct[i] = words[*nxt][i];
                } else if (pattern[i] == 'X') {
                    con.known_incorrect[i] = words[*nxt][i];
                    con.exact.insert(words[*nxt][i]);
                    correct = false;
                } else {
                    con.known_incorrect[i] = words[*nxt][i];
                    con.atleast[words[*nxt][i]]++;
                    correct = false;
                }
            }

            if (correct) {
                return;
            }

            vi nrem;
            iter(it,rem) {
                if (is_consistent(words[*it], con)) {
                    nrem.push_back(*it);
                }
            }

            rec(nrem);
            return;
        }
    }
}

int main() {
    cin >> n;
    assert(n <= MAXN);
    rep(i,0,n) {
        string s;
        cin >> s;
        assert(s.size() == 5);
        words.push_back(s);
    }

    rep(i,0,n) {
        rep(j,0,n) {
            cons[i][j] = derive_constraints(words[i], words[j]);
            rep(k,0,n) {
                is_cons[i][j][k] = is_consistent(words[k], cons[i][j]);
            }
        }
    }
    /* cerr << "done" << endl; */

    vi rem(n);
    rep(i,0,n) rem[i] = i;

    /* cout << dp(rem) << endl; */
    /* cerr << "worst case " << dp(rem) << " moves" << endl; */
    /* cerr << mem.size() << endl; */
    rec(rem);

    return 0;
}


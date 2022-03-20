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

struct constraints {
    map<int,char> known_correct;
    map<int,char> known_incorrect;
    map<char,int> atleast;
    set<char> exact;
};

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

int main() {
    srand(13337);
    int n;
    cin >> n;
    vector<string> words(n);
    rep(i,0,n) {
        cin >> words[i];
    }

    while (true) {
        string guess = words[rand() % words.size()];
        cout << guess << endl;

        string pattern;
        cin >> pattern;

        constraints con;

        bool correct = true;
        rep(i,0,pattern.size()) {
            if (pattern[i] == 'O') {
                con.known_correct[i] = guess[i];
            } else if (pattern[i] == 'X') {
                con.known_incorrect[i] = guess[i];
                con.exact.insert(guess[i]);
                correct = false;
            } else {
                con.known_incorrect[i] = guess[i];
                con.atleast[guess[i]]++;
                correct = false;
            }
        }

        if (correct) {
            break;
        }

        vector<string> consistent;
        iter(it,words) {
            if (is_consistent(*it, con)) {
                consistent.push_back(*it);
            }
        }

        words.swap(consistent);
    }

    return 0;
}


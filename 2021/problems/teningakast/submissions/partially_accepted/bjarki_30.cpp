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
    int ts;
    cin >> ts;

    rep(t,0,ts) {
        string s;
        cin >> s;

        ll mn = 0,
           mx = 0;

        int at = 0;
        while (at < s.size()) {
            int sign = 1;
            ll fst = 0;
            if (at < s.size() && s[at] == '-') {
                sign = -1;
                at++;
            } else if (at < s.size() && s[at] == '+') {
                sign = 1;
                at++;
            }
            while (at < s.size() && '0' <= s[at] && s[at] <= '9') {
                fst = fst * 10 + s[at] - '0';
                at++;
            }
            if (at < s.size() && s[at] == 'd') {
                at++;

                ll snd = 0;
                while (at < s.size() && '0' <= s[at] && s[at] <= '9') {
                    snd = snd * 10 + s[at] - '0';
                    at++;
                }

                if (at < s.size() && s[at] == '!') {
                    at++;
                }

                mn += min(fst * 1 * sign, fst * snd * sign);
                mx += max(fst * 1 * sign, fst * snd * sign);
            } else {
                mn += fst * sign;
                mx += fst * sign;
            }
        }

        ll ans;
        cin >> ans;
        if (mn <= ans && ans <= mx) {
            cout << "Raunhaeft" << endl;
        } else {
            cout << "Svindl" << endl;
        }
    }

    return 0;
}


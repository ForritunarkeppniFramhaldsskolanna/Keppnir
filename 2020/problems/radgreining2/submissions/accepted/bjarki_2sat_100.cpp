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

struct { vi adj; int val, num, lo; bool done; } V[2*10100+100];
struct TwoSat {
  int n, at = 0; vi S;
  TwoSat(int _n) : n(_n) {
    rep(i,0,2*n+1)
      V[i].adj.clear(),
      V[i].val = V[i].num = -1, V[i].done = false; }
  bool put(int x, int v) {
    return (V[n+x].val &= v) != (V[n-x].val &= 1-v); }
  void add_or(int x, int y) {
    V[n-x].adj.push_back(n+y), V[n-y].adj.push_back(n+x); }
  int dfs(int u) {
    int br = 2, res;
    S.push_back(u), V[u].num = V[u].lo = at++;
    iter(v,V[u].adj) {
      if (V[*v].num == -1) {
        if (!(res = dfs(*v))) return 0;
        br |= res, V[u].lo = min(V[u].lo, V[*v].lo);
      } else if (!V[*v].done)
        V[u].lo = min(V[u].lo, V[*v].num);
      br |= !V[*v].val; }
    res = br - 3;
    if (V[u].num == V[u].lo) rep(i,res+1,2) {
      for (int j = (int)size(S)-1; ; j--) {
        int v = S[j];
        if (i) {
          if (!put(v-n, res)) return 0;
          V[v].done = true, S.pop_back();
        } else res &= V[v].val;
        if (v == u) break; }
      res &= 1; }
    return br | !res; }
  bool sat() {
    rep(i,0,2*n+1)
      if (i != n && V[i].num == -1 && !dfs(i)) return false;
    return true; } };
// vim: cc=60 ts=2 sts=2 sw=2:

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, string > > arr;
    rep(i,0,m) {
        int start;
        string s;
        cin >> start >> s;
        start--;
        arr.push_back(make_pair(start, s));
    }

    sort(arr.begin(), arr.end());
    int vs = 0;
    vi var(m, -1);

    vector<pair<int,int> > clauses;

    int longest = -1,
        last = -1;
    rep(i,0,m) {
        if (longest != -1 && arr[i].first + (int)arr[i].second.size() - 1 <= arr[longest].first + (int)arr[longest].second.size() - 1) {
            // I'm inside
            string s = arr[i].second,
                   t = arr[longest].second;

            for (int parentdir = 0; parentdir < 2; parentdir++) {
                bool either = false;
                for (int curdir = 0; curdir < 2; curdir++) {
                    // cout << s << " " << t.substr(arr[i].first - arr[longest].first, arr[i].second.size()) << endl;
                    if (s == t.substr(arr[i].first - arr[longest].first, arr[i].second.size())) {
                        either = true;
                    }

                    reverse(s.begin(), s.end());
                }
                if (!either) {
                    if (parentdir == 0) {
                        clauses.push_back(ii(var[longest], var[longest]));
                    } else {
                        clauses.push_back(ii(-var[longest], -var[longest]));
                    }
                }

                reverse(t.begin(), t.end());
            }
            continue;
        }

        var[i] = ++vs;

        if (last != -1) {
            assert(arr[last].first + (int)arr[last].second.size() - 1 < arr[i].first + (int)arr[i].second.size() - 1);
            if (arr[last].first + (int)arr[last].second.size() - 1 >= arr[i].first) {
                string s = arr[i].second,
                    t = arr[last].second;
                for (int parentdir = 0; parentdir < 2; parentdir++) {
                    for (int curdir = 0; curdir < 2; curdir++) {
                        // cout << s.substr(0, arr[last].first + arr[last].second.size() - arr[i].first) << " " << t.substr(arr[i].first - arr[last].first) << endl;
                        if (s.substr(0, arr[last].first + arr[last].second.size() - arr[i].first) != t.substr(arr[i].first - arr[last].first)) {
                            int a = curdir == 1 ? var[i] : -var[i],
                                b = parentdir == 1 ? var[last] : -var[last];
                            clauses.push_back(ii(-a, -b));
                        }

                        reverse(s.begin(), s.end());
                    }
                    reverse(t.begin(), t.end());
                }
            }
        }

        last = i;
        if (longest == -1 || arr[i].first + (int)arr[i].second.size() - 1 > arr[longest].first + (int)arr[longest].second.size() - 1) {
            longest = i;
        }
    }

    TwoSat ts(vs);
    iter(it,clauses) {
        ts.add_or(it->first, it->second);
    }

    if (!ts.sat()) {
        cout << "Villa" << endl;
        return 0;
    }

    vector<char> ans(n, 0);
    rep(i,0,m) {
        if (var[i] == -1) continue;
        string s = arr[i].second;
        if (V[var[i]+vs].val) {
            reverse(s.begin(), s.end());
        }
        rep(j,0,s.size()) {
            int at = arr[i].first + j;
            if (ans[at] != 0) {
                assert(ans[at] == s[j]);
            }
            ans[at] = s[j];
        }
    }

    rep(i,0,n) {
        if (ans[i] == 0) {
            cout << "A";
        } else {
            cout << ans[i];
        }
    }

    return 0;
}


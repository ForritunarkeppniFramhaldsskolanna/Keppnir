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
    int n, m;
    cin >> n >> m;

    string start, end;
    cin >> start >> end;

    set<string> valid;
    valid.insert(start);
    valid.insert(end);
    rep(i,0,m) {
        string s;
        cin >> s;
        valid.insert(s);
    }

    queue<string> Q;
    Q.push(start);
    map<string,string> back;
    back[start] = start;
    while (!Q.empty()) {
        string cur = Q.front();
        Q.pop();
        if (cur == end) {
            stack<string> S;
            S.push(end);
            int cnt = 0;
            while (S.top() != start) {
                cnt++;
                S.push(back[S.top()]);
            }
            cout << cnt << endl;
            while (!S.empty()) {
                cout << S.top() << endl;
                S.pop();
            }
            return 0;
        }
        vi order;
        rep(i,0,n) order.push_back(i);
        random_shuffle(order.begin(), order.end());
        iter(it,order) {
            int i = *it;
            for (int d = 1; d >= -1; d -= 2) {
                int curd = cur[i] - '0';
                curd += d;
                if (curd < 0) curd += 10;
                if (curd >= 10) curd -= 10;
                string nxt = cur;
                nxt[i] = curd + '0';
                if (valid.find(nxt) != valid.end() && back.find(nxt) == back.end()) {
                    back[nxt] = cur;
                    Q.push(nxt);
                }
            }
        }
    }

    cout << "Neibb" << endl;
    return 0;
}


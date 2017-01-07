#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

template <class T> int size(const T &x) { return x.size(); }

int opposite(int c) {
    return c == 1 ? 2 : 1;
}

int main() {

    int n;
    cin >> n;

    map<string, int> id;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        id[s] = i;
    }

    int m;
    cin >> m;

    vector<int> *adj = new vector<int>[n];
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;

        int x = id[a],
            y = id[b];

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool ok = true;
    int *color = new int[n];
    memset(color, 0, n << 2);

    for (int i = 0; i < n; i++) {
        if (color[i] != 0)
            continue;

        stack<int> S;
        S.push(i);
        color[i] = 1;

        while (!S.empty()) {
            int cur = S.top(); S.pop();

            for (int j = 0; j < size(adj[cur]); j++) {
                int nxt = adj[cur][j];

                if (color[nxt] == 0) {
                    color[nxt] = opposite(color[cur]);
                    S.push(nxt);
                } else {
                    ok = ok && color[nxt] == opposite(color[cur]);
                }
            }
        }
    }

    if (ok) {

        bool first = true;
        for (map<string, int>::const_iterator it = id.begin(); it != id.end(); ++it) {
            if (color[it->second] == 1) {
                if (first) first = false;
                else cout << " ";
                cout << it->first;
            }
        }

        cout << endl;

        first = true;
        for (map<string, int>::const_iterator it = id.begin(); it != id.end(); ++it) {
            if (color[it->second] == 2) {
                if (first) first = false;
                else cout << " ";
                cout << it->first;
            }
        }

        cout << endl;

    } else {
        cout << "impossible" << endl;
    }

    delete[] adj;
    return 0;
}


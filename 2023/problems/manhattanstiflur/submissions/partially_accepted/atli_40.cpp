#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

bool bfs(vvi &g, int a, int b) {
    queue<int> q;
    vi vis(g.size(), 0);
    vis[a] = 1;
    q.push(a);
    while(q.size() > 0) {
        int cur = q.front();
        q.pop();
        for(int x : g[cur]) {
            if(x == b) return true;
            if(vis[x]) continue;
            vis[x] = 1;
            q.push(x);
        }
    }
    return false;
}

int main() {
    int q, n, m, x1, y1, x2, y2;
    cin >> q >> n >> m;
    vvi g((n + 1) * (m + 1), vi());
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            if(i > 0) g[i * (m + 1) + j].push_back((i - 1) * (m + 1) + j);
            if(j > 0) g[i * (m + 1) + j].push_back(i * (m + 1) + j - 1);
            if(i < n) g[i * (m + 1) + j].push_back((i + 1) * (m + 1) + j);
            if(j < m) g[i * (m + 1) + j].push_back(i * (m + 1) + j + 1);
        }
    }
    for(int i = 0; i < q; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        int ind1 = x1 * (m + 1) + y1, ind2 = x2 * (m + 1) + y2;
        auto it1 = find(g[ind1].begin(), g[ind1].end(), ind2);
        if(it1 != g[ind1].end()) g[ind1].erase(it1);
        auto it2 = find(g[ind2].begin(), g[ind2].end(), ind1);
        if(it2 != g[ind2].end()) g[ind2].erase(it2);
        if(!bfs(g, 0, g.size() - 1)) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}

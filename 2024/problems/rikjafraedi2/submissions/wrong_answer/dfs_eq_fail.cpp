#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

bool reach(vvi &g, int s, int t) {
    vi found(g.size(), 0), q;
    found[s] = 1;
    q.push_back(s);
    while(q.size() > 0) {
        int cur = q.back();
        q.pop_back();
        for(int x : g[cur]) {
            if(found[x]) continue;
            if(x == t) return true;
            found[x] = 1;
            q.push_back(x);
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, q, o, x, y;
    cin >> n >> q;
    vvi g(n, vi());
    while(q--) {
        cin >> o >> x >> y;
        x--; y--;
        if(o) cout << (reach(g, x, y) ? "Jebb\n" : "Neibb\n");
        else g[x].push_back(y);
    }
}

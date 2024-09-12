#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define rep(i,a,b) for(auto i = (a); i < (b); ++i)
#define pb push_back

struct incremental_reach {
    int n;
    vvi index;
    vector<vvi> desc;
    incremental_reach(int _n) : n(_n), index(n, vi(n, -1)), desc(n, vvi(1, vi())) {
        rep(i,0,n) index[i][i] = 0;
    }
    bool reachable(int s, int t) {
        return index[s][t] >= 0;
    }
    bool add_edge(int s, int t) {
        if(reachable(s, t)) return false;
        rep(i,0,n) if(reachable(i, s) && !reachable(i, t)) meld(i, t, s, t);
        return true;
    }
    void meld(int r, int s, int u, int v) {
        index[r][v] = desc[r].size();
        desc[r].push_back(vi());
        desc[r][index[r][u]].push_back(v);
        for(int x : desc[s][index[s][v]]) {
            if(!reachable(r, x)) meld(r, s, v, x);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    int n, q, o, x, y;
    cin >> n >> q;
    incremental_reach ir(n);
    while(q--) {
        cin >> o >> x >> y;
        x--; y--;
        if(o) cout << (ir.reachable(x, y) ? "Jebb\n" : "Neibb\n");
        else ir.add_edge(x, y);
    }
}

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vi dkstr(vvii &g, int s) {
    vi rch(g.size(), INT_MAX);
    priority_queue<ii> pq;
    rch[s] = 0;
    pq.push(ii(-rch[s], s));
    while(pq.size() > 0) {
        ii tp = pq.top();
        pq.pop();
        if(rch[tp.second] != -tp.first) continue;
        int cur = tp.second;
        for(ii p : g[cur]) {
            if(max(p.first, rch[cur]) < rch[p.second]) {
                rch[p.second] = max(p.first, rch[cur]);
                pq.push(ii(-rch[p.second], p.second));
            }
        }
    }
    return rch;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, q, o, x, y;
    cin >> n >> q;
    vector<pair<int,ii>> inp;
    vvii full_g(n, vii());
    vi ord, qq, indeg(n, 0);
    for(int i = 0; i < q; ++i) {
        cin >> o >> x >> y;
        inp.push_back(make_pair(o, ii(x - 1, y - 1)));
        if(o == 0) full_g[x - 1].push_back(ii(i, y - 1)), indeg[y - 1]++;
    }
    for(int i = 0; i < n; ++i)
        if(indeg[i] == 0)
            qq.push_back(i);
    while(qq.size() > 0) {
        int cur = qq.back();
        qq.pop_back();
        ord.push_back(cur);
        for(ii p : full_g[cur]) {
            int x = p.second;
            indeg[x]--;
            if(indeg[x] == 0) qq.push_back(x);
        }
    }
    if(ord.size() != n) return 0;
    vi to_ord(n);
    vvi rch_time(n);
    for(int i = 0; i < n; ++i) {
        rch_time[i] = dkstr(full_g, i);
        to_ord[ord[i]] = i;
    }
    for(int i = 0; i < q; ++i) {
        if(inp[i].first == 0) continue;
        int x = inp[i].second.first, y = inp[i].second.second;
        if(to_ord[x] > to_ord[y] || rch_time[x][y] > i) {
            cout << "Neibb\n";
        } else {
            cout << "Jebb\n";
        }
    }
}

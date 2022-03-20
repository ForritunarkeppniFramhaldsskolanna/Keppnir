#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vi dkstr(vvii &g, int s) {
    vi dst(g.size(), INT_MAX);
    priority_queue<ii> pq;
    dst[s] = 0;
    pq.push(ii(-dst[s], s));
    while(pq.size() > 0) {
        int cur = pq.top().second;
        int prvdst = -pq.top().first;
        pq.pop();
        if(prvdst != dst[cur]) continue;
        for(ii p : g[cur]) {
            if(dst[p.second] > dst[cur] + p.first) {
                dst[p.second] = dst[cur] + p.first;
                pq.push(ii(-dst[p.second], p.second));
            }
        }
    }
    return dst;
}

int main() {
    int n, m, u, v, a, b;
    cin >> n >> m;
    vi g(n);
    for(int i = 0; i < n; ++i) cin >> g[i];
    vvii ga(n, vii()), gb(n, vii());
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> a >> b;
        u--; v--;
        ga[u].push_back(ii(a, v));
        ga[v].push_back(ii(a, u));
        gb[u].push_back(ii(b, v));
        gb[v].push_back(ii(b, u));
    }
    vi da = dkstr(ga, 0);
    vi db = dkstr(gb, n - 1);
    int bst = INT_MAX;
    for(int i = 0; i < n; ++i) {
        bst = min(bst, da[i] + db[i] + g[i]);
    }
    cout << bst << '\n';
}

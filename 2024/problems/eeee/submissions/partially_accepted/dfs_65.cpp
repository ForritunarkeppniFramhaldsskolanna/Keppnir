#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k; string s; cin >> n;
    vvi g(n, vi());
    unordered_map<string,int> ind;
    vi outp_ind(n);
    ind.max_load_factor(0.5);
    for(int i = 0; i < n; ++i) {
        cin >> s >> k;
        if(!ind.count(s)) {
            int x = ind.size();
            ind[s] = x;
        }
        int y = ind[s];
        outp_ind[i] = y;
        for(int j = 0; j < k; ++j) {
            cin >> s;
            if(islower(s[0])) continue;
            if(!ind.count(s)) {
                int x = ind.size();
                ind[s] = x;
            }
            g[y].push_back(ind[s]);
        }
    }
    for(int i : outp_ind) {
        vector<bool> rch(n, false); rch[i] = true;
        vector<int> stk; stk.push_back(i);
        int ans = 1;
        while(stk.size() > 0) {
            int cur = stk.back(); 
            stk.pop_back();
            for(int neigh : g[cur]) {
                if(!rch[neigh]) {
                    rch[neigh] = true;
                    stk.push_back(neigh);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}

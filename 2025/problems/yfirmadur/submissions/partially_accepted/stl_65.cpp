#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef vector<int> vi;

int main() {
    int n, q; cin >> n >> q;
    vi par(n); 
    vector<set<int>> ch(n);
    for(int i = 0; i < n; ++i) {
        int p; cin >> p; p--;
        par[i] = p;
        ch[p].insert(i);
    }
    ch[0].erase(0);
    set<int> avail;
    avail.insert(n);
    while(q--) {
        char op; int x;
        cin >> ws >> op >> x;
        x--;
        if(op == '+') {
            int y = *avail.begin();
            avail.erase(avail.begin());
            if(avail.empty())
                avail.insert(y + 1);
            if(y >= par.size()) {
                par.push_back(x);
                ch.emplace_back();
            } else {
                par[y] = x;
                ch[y].clear();
            }
            ch[x].insert(y);
        } else if(op == '-') {
            ch[par[x]].erase(x);
            for(int z : ch[x]) {
                par[z] = par[x];
                ch[par[z]].insert(z);
            }
            ch[x].clear();
            par[x] = -1;
            avail.insert(x);
        } else if(op == '?') {
            cout << par[x] + 1 << '\n';
        }
    }
}

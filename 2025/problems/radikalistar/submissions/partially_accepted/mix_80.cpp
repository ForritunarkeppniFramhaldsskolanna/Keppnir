#include<vector>
#include<map>
#include<set>
#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    map<int,int> group_ind;
    vector<set<int>> groups;
    groups.emplace_back();
    int n, q, nonz = 1; cin >> n >> q;
    if(n <= 100000) {
        for(int i = 0; i < n; ++i) {
            group_ind[i] = 0;
            groups[0].insert(i);
        }
        while(q--) {
            char op; cin >> ws >> op;
            if(op == 'r') {
                map<int,int> sent;
                int m; cin >> m;
                while(m--) {
                    int x; cin >> x; x--;
                    if(!sent.count(group_ind[x])) {
                        sent[group_ind[x]] = groups.size();
                        groups.emplace_back();
                        nonz++;
                    }
                    groups[group_ind[x]].erase(x);
                    if(groups[group_ind[x]].empty()) nonz--;
                    group_ind[x] = sent[group_ind[x]];
                    groups[group_ind[x]].insert(x);
                }
            } else if(op == 's') {
                cout << nonz << '\n';
            } else if(op == 'm') {
                int x; cin >> x; x--;
                for(int y : groups[group_ind[x]]) {
                    cout << y + 1 << ' ';
                }
                cout << '\n';
            }
        }
    } else {
        set<int> alone, orig;
        bool orig_calc = false;
        while(q--) {
            char op;
            cin >> ws >> op;
            if(op == 'r') {
                int x; cin >> x >> x; x--;
                alone.insert(x);
                if(orig_calc)
                    orig.erase(x);
            } else if(op == 's') {
                cout << min(n, (int) alone.size() + 1) << '\n';
            } else if(op == 'm') {
                int x; cin >> x; x--;
                if(alone.count(x)) {
                    cout << x + 1 << '\n';
                } else if(orig_calc) {
                    for(int x : orig)
                        cout << x + 1 << ' ';
                    cout << '\n';
                } else {
                    orig_calc = true;
                    for(int i = 0; i < n; ++i) {
                        if(alone.count(i)) continue;
                        orig.insert(i);
                        cout << i + 1 << ' ';
                    }
                    cout << '\n';
                }
            }
        }
    }
}

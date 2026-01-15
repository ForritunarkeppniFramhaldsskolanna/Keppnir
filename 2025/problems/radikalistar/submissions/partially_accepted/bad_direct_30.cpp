#include<vector>
#include<iostream>
#include<set>
#include<map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, q, counter = 2; cin >> n >> q;
    vector<int> group(n, 1);
    while(q--) {
        char op; cin >> ws >> op;
        if(op == 'r') {
            map<int,int> sent;
            int m; cin >> m;
            while(m--) {
                int x; cin >> x; x--;
                if(!sent.count(group[x])) {
                    sent[group[x]] = counter++;
                }
                group[x] = sent[group[x]];
            }
        } else if(op == 's') {
            set<int> seen;
            for(int i = 0; i < n; ++i)
                seen.insert(group[i]);
            cout << seen.size() << '\n';
        } else if(op == 'm') {
            int x; cin >> x; x--;
            for(int i = 0; i < n; ++i)
                if(group[i] == group[x])
                    cout << i + 1 << ' ';
            cout << '\n';
        }
    }
}

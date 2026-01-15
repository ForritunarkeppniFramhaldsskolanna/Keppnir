#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef vector<int> vi;

int main() {
    int n, q; cin >> n >> q;
    vi par(n); 
    for(int i = 0; i < n; ++i) {
        int p; cin >> p; p--;
        par[i] = p;
    }
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
            par.push_back(x);
        } else if(op == '-') {
            continue;
        } else if(op == '?') {
            cout << par[x] + 1 << '\n';
        }
    }
}

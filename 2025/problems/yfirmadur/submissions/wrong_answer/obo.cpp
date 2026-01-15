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
    while(q--) {
        char op; int x;
        cin >> ws >> op >> x;
        x--;
        if(op == '+') {
            continue;
        } else if(op == '-') {
            continue;
        } else if(op == '?') {
            cout << par[x] << '\n';
        }
    }
}

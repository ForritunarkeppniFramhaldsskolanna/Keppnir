#include<bits/stdc++.h>
using namespace std;

bool rec_solve(int d, int k, vector<int> a, vector<int> b) {
    if(d > k) return true;
    for(int i = 0; i < a.size(); ++i) {
        if(b[i] < d) continue;
        if(a[i] < 4) continue;
        for(int j = i + 1; j < a.size(); ++j) {
            if(b[j] < d) continue;
            if(a[j] < 4) continue;
            if(a[i] + a[j] < 9) continue;
            vector<int> acp = a, bcp = b;
            acp.erase(acp.begin() + max(i, j));
            bcp.erase(bcp.begin() + max(i, j));
            acp.erase(acp.begin() + min(i, j));
            bcp.erase(bcp.begin() + min(i, j));
            if(rec_solve(d + 1, k, acp, bcp)) return true;
        }
    }
    return false;
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    cout << (rec_solve(1, k, a, b) ? "Jebb\n" : "Neibb\n");
}

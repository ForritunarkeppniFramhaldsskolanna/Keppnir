#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int p, n; char c;
    cin >> ws >> c >> c >> p >> n;
    if(p == 0) {
        cout << "Neibb\n";
        return 0;
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        if(s == "ekki") {
            cnt++;
            cin >> s;
        }
    }
    if(100 * cnt <= n * p) cout << "Jebb\n";
    else cout << "Neibb\n";
}

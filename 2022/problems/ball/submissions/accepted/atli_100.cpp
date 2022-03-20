#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
    int n, x; cin >> n;
    vi cnt(n, 0);
    for(int i = 0; i < n + 2; ++i) {
        cin >> x; x--; cnt[x]++;
    }
    for(int i = 0; i < n; ++i) {
        if(cnt[i] > 1) {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
}

#include<bits/stdc++.h>
using namespace std;

void dirty_add(int k, int c, string &s) {
    s[s.size() - k - 1] += c;
    for(int i = s.size() - k - 1; i >= 1; --i) {
        if(s[i] <= '9') break;
        s[i] -= 10;
        s[i - 1]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    string n; cin >> n;
    cout << n << '\n';
    n = "0" + n;
    dirty_add(0, 2, n);
    string digs(n.size(), '0');
    int pos = 0;
    while(pos < n.size()) {
        if(pos == n.size() - 1 && n[pos] <= '2') break;
        if(n[pos] >= '3') {
            dirty_add(n.size() - pos - 1, 1, digs);
            n[pos] -= 3;
            continue;
        }
        if(n[pos] >= '1') {
            dirty_add(n.size() - pos - 2, 3, digs);
            n[pos]--;
            dirty_add(n.size() - pos - 2, 1, n);
            continue;
        }
        pos++;
    }
    bool start = false;
    for(char c : digs) {
        if(c != '0') {
            start = true;
        }
        if(start) cout << c;
    }
    cout << '\n';
}

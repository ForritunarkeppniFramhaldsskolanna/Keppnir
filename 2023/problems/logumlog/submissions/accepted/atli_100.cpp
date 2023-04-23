#include<bits/stdc++.h>
using namespace std;

int locs[7] = { 9, 11, 0, 2, 4, 5, 7 };

int read_note() {
    string s, t = "";
    cin >> s;
    if(s == "-") return -1;
    int res = locs[s[0] - 'A'];
    for(char c : s) {
        if(isdigit(c)) t.push_back(c);
        if(c == '#') res++;
        if(c == 'b') res--;
    }
    if(t == "") t = "1";
    res += 12 * stoi(t);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) a[i] = read_note();
    for(int i = 0; i < n; ++i) b[i] = read_note();
    int offs = INT_MAX;
    for(int i = 0; i < n; ++i) {
        if((a[i] == -1) != (b[i] == -1)) {
            cout << "Neibb\n";
            return 0;
        } 
        if(a[i] == -1 || b[i] == -1) continue;
        if(offs == INT_MAX) {
            offs = a[i] - b[i];
        } else if(a[i] - b[i] != offs) {
            cout << "Neibb\n";
            return 0;
        }
    }
    cout << "Jebb\n";
}

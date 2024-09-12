#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<pair<string,string>> dat;
    for(int i = 0; i < n; ++i) {
        string s, t;
        cin >> s >> t;
        s.pop_back();
        dat.push_back(make_pair(t, s));
    }
    sort(dat.begin(), dat.end());
    map<string,int> ind;
    for(int i = 0; i < n; ++i) {
        ind[dat[i].second] = i + 1;
    }
    for(int i = 0; i < q; ++i) {
        string s; cin >> s;
        if(ind.count(s)) cout << ind[s] << '\n';
        else cout << -1 << '\n';
    }
}

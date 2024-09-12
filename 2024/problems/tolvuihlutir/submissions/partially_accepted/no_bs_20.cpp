#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;

void quit() {
    cout << "O nei!\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k, p; cin >> n >> k >> p;
    map<string,int> inds;
    vvii dat(k);
    for(int i = 0; i < k; ++i) {
        string s; cin >> s;
        inds[s] = i;
    }
    for(int i = 0; i < n; ++i) {
        string s; int v, g;
        cin >> s >> v >> g;
        dat[inds[s]].push_back(ii(v, g));
    }
    ll mncost = 0;
    for(int i = 0; i < k; ++i) {
        if(dat[i].empty()) quit();
        sort(dat[i].begin(), dat[i].end());
        mncost += dat[i][0].first;
        vii nw;
        nw.push_back(dat[i][0]);
        for(int j = 1; j < dat[i].size(); ++j) {
            if(dat[i][j].second > nw.back().second)
                nw.push_back(dat[i][j]);
        }
        dat[i] = nw;
        for(int j = 0; j < dat[i].size(); ++j)
            dat[i][j] = ii(dat[i][j].second, dat[i][j].first);
    }
    if(mncost > p) quit();
    int bst = 0, cur = 0;
    while(true) {
        ll cost = 0;
        for(int i = 0; i < k; ++i) {
            if(dat[i].back().first < cur) {
                cost = LLONG_MAX;
                break;
            }
            for(int j = 0; j < dat[i].size(); ++j) {
                if(dat[i][j].first >= cur) {
                    cost += dat[i][j].second;
                    break;
                }
            }
        }
        if(cost > p) break;
        else bst = max(bst, cur);
        cur++;
    }
    cout << bst << '\n';
}

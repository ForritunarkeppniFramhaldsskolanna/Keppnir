#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k, x;
    string car;
    cin >> n >> k;
    map<string,int> car2corp;
    vector<int> corp_lim(k);
    for(int i = 0; i < k; ++i) {
        cin >> corp_lim[i] >> x;
        for(int j = 0; j < x; ++j) {
            cin >> car;
            car2corp[car] = i;
        }
    }
    set<string> parked, unpins;
    vector<set<string>> corp_cur(k);
    set<string> illegal;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        cin >> car;
        if(unpins.count(car)) {
            unpins.erase(car);
            continue;
        }
        if(parked.count(car)) {
            parked.erase(car);
            if(car2corp.count(car)) {
                corp_cur[car2corp[car]].erase(car);
            }
            continue;
        }
        if(parked.size() == n) {
            illegal.insert(car);
            unpins.insert(car);
            continue;
        }
        parked.insert(car);
        if(!car2corp.count(car)) {
            illegal.insert(car);
            continue;
        }
        int ind = car2corp[car];
        corp_cur[ind].insert(car);
        if(corp_cur[ind].size() > corp_lim[ind]) {
            illegal.insert(car);
        }
    }
    cout << illegal.size() << '\n';
    for(string s : illegal) cout << s << '\n';
}

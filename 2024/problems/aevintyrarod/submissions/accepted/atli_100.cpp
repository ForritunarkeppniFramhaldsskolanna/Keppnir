#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<string,ii> quest;
typedef long long ll;

struct {
    bool operator()(const quest &a, const quest &b) const {
        if(b.second.first == 0) return false;
        if(a.second.first == 0) return true;
        ll x = a.second.second, y = b.second.second;
        x *= b.second.first; y *= a.second.first;
        return x > y;
    }
} questSort;

int main() {
    int n, c; cin >> n >> c;
    vector<quest> quests;
    for(int i = 0; i < n; ++i) {
        string s; int a, b;
        cin >> s >> a >> b;
        quests.push_back(quest(s, ii(a, b)));
    }
    sort(quests.begin(), quests.end(), questSort);
    for(int i = 0; i < n; ++i) {
        cout << quests[i].first << '\n';
    }
}

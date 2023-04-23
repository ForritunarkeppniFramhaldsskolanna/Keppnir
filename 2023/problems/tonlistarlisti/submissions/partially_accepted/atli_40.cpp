#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    int q; cin >> q;
    map<string,int> id;
    vector<pair<int,ll>> playlist;
    ll length = 0;
    for(int i = 0; i < q; ++i) {
        char c; cin >> ws >> c;
        if(c == 'P') {
            int t; cin >> t;
            if(t >= length) {
                int plays = t / length;
                t %= length;
                for(int j = 0; j < playlist.size(); ++j)
                    playlist[j].second += plays;
            }
            for(int j = playlist.size() - 1; j >= 0; --j) {
                if(playlist[j].first > t) break;
                playlist[j].second++;
                t -= playlist[j].first;
            }
        } else if(c == 'L') {
            string s; int sec;
            cin >> s >> sec;
            id[s] = playlist.size();
            playlist.push_back(make_pair(sec, 0));
            length += sec;
        } else if(c == 'Q') {
            string s; cin >> s;
            cout << (id.count(s) ? playlist[id[s]].second : 0) << '\n';
        }
    }
}


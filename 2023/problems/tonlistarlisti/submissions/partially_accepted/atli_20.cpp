#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    int q; cin >> q;
    map<string,int> id;
    vector<ll> playlist;
    for(int i = 0; i < q; ++i) {
        char c; cin >> ws >> c;
        if(c == 'P') {
            int t; cin >> t;
            if(t >= playlist.size()) {
                int plays = t / playlist.size();
                t %= playlist.size();
                for(int j = 0; j < playlist.size(); ++j)
                    playlist[j] += plays;
            }
            for(int j = playlist.size() - 1; j >= playlist.size() - t; --j) {
                playlist[j]++;
            }
        } else if(c == 'L') {
            string s; int sec;
            cin >> s >> sec;
            id[s] = playlist.size();
            playlist.push_back(0);
        } else if(c == 'Q') {
            string s; cin >> s;
            cout << (id.count(s) ? playlist[id[s]] : 0) << '\n';
        }
    }
}


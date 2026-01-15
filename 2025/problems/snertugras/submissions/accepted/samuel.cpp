#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int bfs(pair<int, int> s, vector<string> &mp) {
    int dist[mp.size()][mp[0].size()];
    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> q;
    q.push(s);
    dist[s.first][s.second] = 0;

    while (!q.empty()) {
        pair<int, int> at = q.front();
        q.pop();

        int d = dist[at.first][at.second];

        if (at.first > 0) {
            if (dist[at.first - 1][at.second] == -1) {
                if (mp[at.first - 1][at.second] == '.') {
                    dist[at.first - 1][at.second] = d + 1;
                    q.push({at.first - 1, at.second});
                }
                else if (mp[at.first - 1][at.second] == 'G')
                    return d + 1;
            }
        }
        if (at.second > 0) {
            if (dist[at.first][at.second - 1] == -1) {
                if (mp[at.first][at.second - 1] == '.') {
                    dist[at.first][at.second - 1] = d + 1;
                    q.push({at.first, at.second - 1});
                }
                else if (mp[at.first][at.second - 1] == 'G')
                    return d + 1;
            }
        }
        if (at.first < mp.size() - 1) {
            if (dist[at.first + 1][at.second] == -1) {
                if (mp[at.first + 1][at.second] == '.') {
                    dist[at.first + 1][at.second] = d + 1;
                    q.push({at.first + 1, at.second});
                }
                else if (mp[at.first + 1][at.second] == 'G')
                    return d + 1;
            }
        }
        if (at.second < mp[0].size() - 1) {
            if (dist[at.first][at.second + 1] == -1) {
                if (mp[at.first][at.second + 1] == '.') {
                    dist[at.first][at.second + 1] = d + 1;
                    q.push({at.first, at.second + 1});
                }
                else if (mp[at.first][at.second + 1] == 'G')
                    return d + 1;
            }
        }
    }
    return -1;
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> mp(h);

    pair<int, int> start = {0, 0};
    
    for (int i = 0; i < h; i++) {
        cin >> mp[i];
        for (int j = 0; j < w; j++) {
            if (mp[i][j] == 'S') {
                start = {i, j};
            }
        }
    }

    int ans = bfs(start, mp);
    if (ans == -1) {
        cout << "thralatlega nettengdur" << endl;
    } else {
        cout << ans << endl;
    }
}
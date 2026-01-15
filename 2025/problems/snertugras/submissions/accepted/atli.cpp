#include<queue>
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> i3;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h, w; cin >> h >> w;
    vector<string> inp(h);
    for(int i = 0; i < h; ++i)
        cin >> inp[i];
    int s_x = -1, s_y = -1;
    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j)
            if(inp[i][j] == 'S')
                s_x = i, s_y = j;
    vector<vector<int>> dst(h, vector<int>(w, INT_MAX));
    dst[s_x][s_y] = 0;
    priority_queue<i3, vector<i3>, greater<i3>> pq;
    pq.push(i3(0, ii(s_x, s_y)));
    while(pq.size() > 0) {
        int ww = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(dst[x][y] != ww) continue;
        for(int di = 0; di < 4; ++di) {
            int nx = x + dx[di];
            int ny = y + dy[di];
            if(nx < 0 || ny < 0) continue;
            if(nx >= h || ny >= w) continue;
            if(dst[nx][ny] <= dst[x][y] + 1) continue;
            if(inp[nx][ny] == '#') continue;
            dst[nx][ny] = dst[x][y] + 1;
            pq.push(i3(dst[nx][ny], ii(nx, ny)));
        }
    }
    int bst = INT_MAX;
    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j)
            if(inp[i][j] == 'G')
                bst = min(bst, dst[i][j]);
    if(bst == INT_MAX) cout << "thralatlega nettengdur\n";
    else cout << bst << '\n';
}


#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
    }

    int start_row, start_col;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == 'S') {
                start_row = i;
                start_col = j;
                break;
            }
        }
    }

    queue<tuple<int, int, int>> q;
    q.push({start_row, start_col, 0});

    vector<vector<bool>> visited(h, vector<bool>(w, false));
    visited[start_row][start_col] = true;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [row, col, dist] = q.front();
        q.pop();

        if (grid[row][col] == 'G') {
            cout << dist << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];

            if (new_row >= 0 && new_row < h && new_col >= 0 && new_col < w &&
                grid[new_row][new_col] != '#' && !visited[new_row][new_col]) {
                visited[new_row][new_col] = true;
                q.push({new_row, new_col, dist + 1});
            }
        }
    }

    cout << "thralatlega nettengdur" << endl;

    return 0;
}

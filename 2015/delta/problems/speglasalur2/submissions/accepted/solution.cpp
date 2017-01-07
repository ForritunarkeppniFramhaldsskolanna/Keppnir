#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T &x) { return x.size(); }

// assert or gtfo

bool is_bjorn(char c) {
    return c == '<' || c == '>' || c == 'v' || c == '^';
}

bool is_wall(char c) {
    return c == '|' || c == '-' || c == '+' || is_bjorn(c);
}

bool is_mirror(char c) {
    return c == '/' || c == '\\';
}

ii get_dir(char c) {
    if (c == '<') return ii(0, -1);
    if (c == '^') return ii(-1, 0);
    if (c == '>') return ii(0, 1);
    if (c == 'v') return ii(1, 0);
    assert(false);
}

ii rotate_left(int dx, int dy) {
    return ii(-dy, dx);
}

ii rotate_right(int dx, int dy) {
    return ii(dy, -dx);
}

ii get_new_dir(char c, int dx, int dy) {
    if (c == '/') {
        if (dx == 0) {
            return rotate_left(dx, dy);
        } else {
            return rotate_right(dx, dy);
        }
    } else if (c == '\\') {
        if (dx == 0) {
            return rotate_right(dx, dy);
        } else {
            return rotate_left(dx, dy);
        }
    } else {
        assert(false);
    }
}

string board[8];

int main() {

    int x = -1,
        y = -1,
        dx = 0,
        dy = 0;

    for (int i = 0; i < 8; i++) {
        getline(cin, board[i]);
        for (int j = 0; j < 8; j++) {
            if (is_bjorn(board[i][j])) {
                x = i;
                y = j;

                ii dir = get_dir(board[i][j]);
                dx = dir.first;
                dy = dir.second;
            }
        }
    }

    assert(x != -1 && y != -1);

    int cnt = 0;
    x += dx;
    y += dy;
    while (!is_wall(board[x][y])) {

        if (is_mirror(board[x][y])) {

            ii dir = get_new_dir(board[x][y], dx, dy);
            dx = dir.first;
            dy = dir.second;
            x += dx;
            y += dy;
            cnt++;

        } else {
            x += dx;
            y += dy;
        }
    }

    cout << cnt << endl;

    return 0;
}


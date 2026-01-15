#include "validate.h"
#include "fraction.h"
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

// weighted graph, weight 0 is rg, 1 is yy, 2 is gr
vvii read_graph(istream &in, feedback_function f, int line_num) {
    int n;
    if(!(in >> n)) {
        f("Failed to read number of intersections.\n");
    }
    vvii g(line_num);
    for(int i = 0; i < n; ++i) {
        int x, y;
        if(!(in >> x >> y)) {
            f("Failed to read indices on line " + to_string(i) + " of output.\n");
        }
        if(x <= 0 || y <= 0 || x > line_num || y > line_num) {
            f("Indices on line " + to_string(i) + " of output out of bounds.\n");
        }
        if(x == y) {
            f("Indices on line " + to_string(i) + " of output are equal.\n");
        }
        char c1, c2;
        if(!(in >> ws >> c1 >> ws >> c2)) {
            f("Failed to read colours on line " + to_string(i) + " of output.\n");
        }
        if(c1 != 'r' || c2 != 'g') {
            if(c1 != 'g' || c2 != 'r') {
                if(c1 != 'y' || c2 != 'y') {
                    f("Colours on line " + to_string(i) + " of output are not rg, gr or yy.\n");
                }
            }
        }
        int w = 0; 
        if(c1 == 'y') w = 1;
        if(c1 == 'g') w = 2;
        x--; y--;
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, 2 - w);
    }
    for(int i = 0; i < line_num; ++i) {
        sort(g[i].begin(), g[i].end());
    }
    string trailing;
    if(in >> trailing) {
        f("Trailing output.\n");
    }
    return g;
}

typedef fraction<__int128> coord;
typedef pair<coord,coord> point;

point intersect(__int128 x1, __int128 y1, __int128 x2, __int128 y2,
    __int128 x3, __int128 y3, __int128 x4, __int128 y4) {
    __int128 d1 = x1 * y2 - y1 * x2, d2 = x3 * y4 - y3 * x4;
    __int128 n1 = d1 * (x3 - x4) - (x1 - x2) * d2;
    __int128 n2 = d1 * (y3 - y4) - (y1 - y2) * d2;
    __int128 m = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if(x1 == x3 && y1 == y3)
        return make_pair(coord(x1, 1), coord(y1, 1));
    if(x1 == x4 && y1 == y4)
        return make_pair(coord(x1, 1), coord(y1, 1));
    if(x2 == x3 && y2 == y3)
        return make_pair(coord(x2, 1), coord(y2, 1));
    if(x2 == x4 && y2 == y4)
        return make_pair(coord(x2, 1), coord(y2, 1));
    return make_pair(coord(n1, m), coord(n2, m));
}

int main(int argc, char **argv) {
    init_io(argc, argv);
    
    int n; judge_in >> n;
    vector<int> x1(n), y1(n), x2(n), y2(n);
    for(int i = 0; i < n; ++i) {
        judge_in >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }
    
    vvii judge_graph = read_graph(judge_ans, judge_message, n);
    vvii author_graph = read_graph(author_out, wrong_answer, n);

    for(int i = 0; i < n; ++i) {
        if(judge_graph[i].size() != author_graph[i].size()) {
            wrong_answer("Line " + to_string(i) + " has the wrong number of intersections.\n");
        }
        for(int j = 0; j < judge_graph[i].size(); ++j) {
            if(judge_graph[i][j].first != author_graph[i][j].first) {
                wrong_answer("Line " + to_string(i) + " has the wrong intersections.\n");
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        int m = judge_graph[i].size();
        vector<point> sects(m);
        for(int j = 0; j < m; ++j) {
            int k = judge_graph[i][j].first;
            sects[j] = intersect(x1[i], y1[i], x2[i], y2[i], x1[k], y1[k], x2[k], y2[k]);
        }
        vector<point> sorted_sects = sects;
        sort(sorted_sects.begin(), sorted_sects.end());
        map<point,int> index;
        for(int j = 0; j < m; ++j) {
            index[sorted_sects[j]] = j;
        }
        vector<int> colours(m, ' ');
        for(int j = 0; j < m; ++j) {
            int c = author_graph[i][j].second;
            colours[index[sects[j]]] = c;
        }
        
        for(int j = 1; j < m; ++j) {
            if(colours[j] == colours[j - 1]) {
                wrong_answer("Consecutive lights with same colour on line " + to_string(i) + ".\n");
            }
        }
    }

    accept();
}

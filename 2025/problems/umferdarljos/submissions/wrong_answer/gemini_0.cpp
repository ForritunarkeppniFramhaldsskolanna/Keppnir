#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Point {
    long long x, y;
};

struct Line {
    Point p1, p2;
    int id;
};

long long cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool on_segment(Point p, Point a, Point b) {
    if (cross_product(a, b, p) != 0) return false;
    return (p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) &&
            p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y));
}

pair<bool, Point> intersection(Line l1, Line l2) {
    long long a1 = l1.p2.y - l1.p1.y;
    long long b1 = l1.p1.x - l1.p2.x;
    long long c1 = -a1 * l1.p1.x - b1 * l1.p1.y;

    long long a2 = l2.p2.y - l2.p1.y;
    long long b2 = l2.p1.x - l2.p2.x;
    long long c2 = -a2 * l2.p1.x - b2 * l2.p1.y;

    long long det = a1 * b2 - a2 * b1;
    if (det == 0) {
        return {false, {0, 0}};
    }

    Point p;
    p.x = (b1 * c2 - b2 * c1) / det;
    p.y = (a2 * c1 - a1 * c2) / det;

    if (on_segment(p, l1.p1, l1.p2) && on_segment(p, l2.p1, l2.p2)) {
        return {true, p};
    }
    return {false, {0, 0}};
}

int main() {
    int n;
    cin >> n;

    vector<Line> lines(n);
    for (int i = 0; i < n; ++i) {
        cin >> lines[i].p1.x >> lines[i].p1.y >> lines[i].p2.x >> lines[i].p2.y;
        lines[i].id = i + 1;
    }

    vector<tuple<int, int, char, char>> intersections;
    vector<pair<Point, pair<int, int>>> intersection_points;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto res = intersection(lines[i], lines[j]);
            if (res.first) {
                intersection_points.push_back({res.second, {lines[i].id, lines[j].id}});
            }
        }
    }

    cout << intersection_points.size() << endl;

    for(auto& ip : intersection_points) {
          cout << ip.second.first << " " << ip.second.second << " ";
          if ((ip.second.first + ip.second.second) % 3 == 0)
              cout << "r g" << endl;
          else if ((ip.second.first + ip.second.second) % 3 == 1)
              cout << "g r" << endl;
          else 
              cout << "y y" << endl;
    }
    

    return 0;
}

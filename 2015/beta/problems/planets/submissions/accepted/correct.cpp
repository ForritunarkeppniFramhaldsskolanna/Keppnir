#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define foreach(u, o) \
    for (typeof((o).begin()) u = (o).begin(); u != (o).end(); ++u)
const int INF = 2147483647;
const double EPS = 1e-9;
const double pi = acos(-1);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T mod(T a, T b) { return (a % b + b) % b; }
template <class T> int size(const T &x) { return x.size(); }

const int MX = 1000000;

struct point {
    double x, y, z;

    point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
    point() : x(0.0), y(0.0), z(0.0) {}
};

double dist(point& p1, point &p2) {
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) +
                (p1.y-p2.y)*(p1.y-p2.y) +
                (p1.z-p2.z)*(p1.z-p2.z));
}

int main() {
    int N;
    cin >> N;
    point earth;
    cin >> earth.x >> earth.y >> earth.z;
    vector<point> planets(N);
    for(int i = 0; i < N; ++i){
        cin >> planets[i].x >> planets[i].y >> planets[i].z;
    }

    double mindist = 1e+6;
    double maxdist = 0.0;
    int mindistp, maxdistp;
    for(int i = 0; i < N; ++i){
        double distance = dist(earth, planets[i]);
        if(distance - maxdist > EPS){
            maxdistp = i;
            maxdist = distance;
        }
        if(mindist - distance > EPS){
            mindistp = i;
            mindist = distance;
        }
    }

    printf("%d %.4lf\n", mindistp, round(10000.0*mindist)/10000.0);
    printf("%d %.4lf\n", maxdistp, round(10000.0*maxdist)/10000.0);
}

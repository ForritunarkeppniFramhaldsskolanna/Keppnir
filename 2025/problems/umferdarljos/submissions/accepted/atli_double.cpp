#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<functional>
#include<complex>
#include<cfloat>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

const long double EPS = 1e-7;
typedef complex<long double> point;

const point DUMMY(DBL_MAX, DBL_MAX);

bool eq(long double a, long double b) {
    if(abs(a - b) < EPS) return true;
    return false;
}

point intersect(int x1, int y1, int x2, int y2,
    int x3, int y3, int x4, int y4) {
    if(x1 == x3 && y1 == y3)
        return point(x1, y1);
    if(x1 == x4 && y1 == y4)
        return point(x1, y1);
    if(x2 == x3 && y2 == y3)
        return point(x2, y2);
    if(x2 == x4 && y2 == y4)
        return point(x2, y2);
    long double x1d = x1, y1d = y1, x2d = x2, y2d = y2;
    long double x3d = x3, y3d = y3, x4d = x4, y4d = y4;
    long double m = (x1d - x2d) * (y3d - y4d) - (y1d - y2d) * (x3d - x4d);
    if(eq(abs(m), 0)) return DUMMY;
    long double d1 = x1d * y2d - y1d * x2d, d2 = x3d * y4d - y3d * x4d;
    long double n1 = d1 * (x3d - x4d) - (x1d - x2d) * d2;
    long double n2 = d1 * (y3d - y4d) - (y1d - y2d) * d2;
    long double c1 = n1 / m, c2 = n2 / m;
    if(c1 < min(x1, x2) - EPS || c1 > max(x1, x2) + EPS)
        return DUMMY;
    if(c2 < min(y1, y2) - EPS || c2 > max(y1, y2) + EPS)
        return DUMMY;
    if(c1 < min(x3, x4) - EPS || c1 > max(x3, x4) + EPS)
        return DUMMY;
    if(c2 < min(y3, y4) - EPS || c2 > max(y3, y4) + EPS)
        return DUMMY;
    return point(c1, c2);
}

bool point_le(point a, point b) {
    if(abs(a.real() - b.real()) < EPS)
        return a.imag() < b.imag();
    return a.real() < b.real();
}

struct event {
    point p;
    int i1, i2, type;

    event(point _p, int _t, int _i1, int _i2) : p(_p), i1(_i1), i2(_i2), type(_t) { }

    friend bool operator <(const event &e, const event &f) {
        if(eq(abs(e.p - f.p), 0))
            return e.type < f.type;
        return point_le(e.p, f.p);
    }
    friend bool operator >(const event &e, const event &f) {
        if(eq(abs(e.p - f.p), 0))
            return e.type > f.type;
        return point_le(f.p, e.p);
    }
};

long double cross(point a, point b) {
    return a.real() * b.imag() - a.imag() * b.real();
}

long double ccw(point a, point b, point c) {
    return cross(b - a, c - b);
}

typedef set<int>::iterator sl_it;

int point_cmp(const point &a, const point &b) {
    if(eq(abs(a.real() - b.real()), 0))
        return a.imag() < b.imag();
    return a.real() < b.real();
};

struct sweeper {
    priority_queue<event, vector<event>, greater<event>> pq;
    function<int(const int &a, const int &b)> sweep_cmp;
    set<int, decltype(sweep_cmp)> sl;
    set<pair<int,int>> sected;
    vector<sl_it> sl_loc;
    map<point, int, decltype(point_cmp)*> index;
    vector<vector<point>> sects;
    vector<point> allpts;
    vector<int> x1, y1, x2, y2, s1, s2;
    int n;

    point x_sweep = point(-1000001, 0);

    sweeper(vector<int> _x1, vector<int> _y1, 
        vector<int> _x2, vector<int> _y2) :
            x1(_x1), y1(_y1), x2(_x2), y2(_y2) {
        n = x1.size();
        sects.resize(n);
        sl_loc.resize(n);

        sweep_cmp = [&](const int &a, const int &b) {
            point sect1, sect2;
            if(x1[a] != x2[a]) {
                long double slope = (y2[a] - y1[a]);
                slope /= (x2[a] - x1[a]);
                long double sect1y = y1[a] + (x_sweep.real() - x1[a]) * slope;
                sect1 = point(x_sweep.real(), sect1y);
            } else {
                sect1 = x_sweep;
            }
            if(x1[b] != x2[b]) {
                long double slope = (y2[b] - y1[b]);
                slope /= (x2[b] - x1[b]);
                long double sect2y = y1[b] + (x_sweep.real() - x1[b]) * slope;
                sect2 = point(x_sweep.real(), sect2y);
            } else {
                sect2 = x_sweep;
            }
            if(eq(abs(sect1 - sect2), 0)) {
                if(x1[a] == x2[a] && x1[b] == x2[b]) {
                    return y1[a] < y1[b];
                }
                if(x1[a] == x2[a]) {
                    return false;
                }
                if(x1[b] == x2[b]) {
                    return true;
                }
                long double slope1 = (y2[a] - y1[a]);
                slope1 /= (x2[a] - x1[a]);
                long double slope2 = (y2[b] - y1[b]);
                slope2 /= (x2[b] - x1[b]);
                if(eq(abs(slope1 - slope2), 0))
                    return tie(x1[a], y1[a]) < tie(x1[b], y1[b]);
                return slope1 < slope2;
            }
            return point_le(sect1, sect2);
        };

        sl = set<int, decltype(sweep_cmp)>(sweep_cmp);
        index = map<point, int, decltype(point_cmp)*>(point_cmp);
    }

    void register_sect(point p, int a, int b) {
        sected.insert(make_pair(a, b));
        sected.insert(make_pair(b, a));
        if(index.count(p)) return;
        int x = index.size();
        index[p] = x;
        allpts.push_back(p);
        sects[a].push_back(p);
        sects[b].push_back(p);
        s1.push_back(a);
        s2.push_back(b);
    }

    void add_neigh_sect(sl_it it) {
        int a = *it;
        for(int i = 0; i < 2; ++i) {
            if(i == 0 && it == sl.begin())
                continue;
            auto it2 = it;
            if(i == 0) it2--;
            else it2++;
            if(it2 == sl.end()) continue;
            int b = *it2;
            if(sected.count(make_pair(a, b))) continue;
            point sect = intersect(x1[a], y1[a], x2[a], y2[a], x1[b], y1[b], x2[b], y2[b]);
            //cout << "CHECKING " << a << ' ' << b << endl;
            if(sect == DUMMY) continue;
            // cout << sect << ' ' << x_sweep << endl;
            if(point_le(sect, x_sweep)) continue;
            pq.push(event(sect, 0, a, b));
        }
    }

    void initialize() {
        for(int i = 0; i < n; ++i) {
            pq.push(event(point(x1[i], y1[i]), 1, i, i));
            pq.push(event(point(x2[i], y2[i]), 2, i, i));
        }
    }

    void process_next() {
        point cur = pq.top().p;
        int typ = pq.top().type;
        int ind1 = pq.top().i1;
        int ind2 = pq.top().i2;
        //for(int x : sl)
        //cout << x << ' ';
        //cout << endl;
        pq.pop();
        x_sweep = cur;
        if(typ == 2) {
            // cout << "ERASING " << ind1 << endl;
            vector<sl_it> to_check;
            auto cp = sl_loc[ind1];
            if(cp != sl.begin()) {
                cp--;
                to_check.push_back(cp);
            }
            cp = sl_loc[ind1]; cp++;
            if(cp != sl.end()) {
                to_check.push_back(cp);
            }
            sl.erase(sl_loc[ind1]);
            sl_loc[ind1] = sl.end();
            for(auto cp : to_check)
                add_neigh_sect(cp);
        } else if(typ == 0) {
            if(sected.count(make_pair(ind1, ind2)))
                return;
            auto it1 = sl_loc[ind1];
            auto it2 = sl_loc[ind2];
            bool adj = false;
            auto cp1 = it1; cp1++;
            adj |= cp1 == it2;
            auto cp2 = it2; cp2++;
            adj |= cp2 == it1;
            if(adj) {
                register_sect(cur, ind1, ind2);
                // cout << "INTERSECTING " << ind1 << ' ' << ind2 << endl;
                auto val1 = *it1;
                auto val2 = *it2;
                sl.erase(it1);
                sl.erase(it2);
                it1 = sl.insert(val1).first;
                it2 = sl.insert(val2).first;
                sl_loc[ind1] = it1;
                sl_loc[ind2] = it2;
                add_neigh_sect(it1);
                add_neigh_sect(it2);
            }
        } else if(typ == 1) {
            // cout << "ADDING " << ind1 << endl;
            sl_loc[ind1] = sl.insert(ind1).first;
            add_neigh_sect(sl_loc[ind1]);
        } else assert(false);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> x1(n), y1(n), x2(n), y2(n);
    for(int i = 0; i < n; ++i) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        if(x1[i] > x2[i]) {
            swap(x1[i], x2[i]);
            swap(y1[i], y2[i]);
        }
        if(x1[i] == x2[i] && y1[i] > y2[i]) {
            swap(y1[i], y2[i]);
        }
    }
    sweeper sw(x1, y1, x2, y2);
    sw.initialize();
    while(sw.pq.size() > 0)
        sw.process_next();
    vector<vector<pair<int,int>>> prvs(sw.index.size());
    for(int i = 0; i < n; ++i) {
        sort(sw.sects[i].begin(), sw.sects[i].end(), point_cmp);
        for(int j = 1; j < sw.sects[i].size(); ++j) {
            prvs[sw.index[sw.sects[i][j]]].emplace_back(sw.index[sw.sects[i][j - 1]], i);
        }
    }
    sort(sw.allpts.begin(), sw.allpts.end(), point_cmp);
    cout << sw.allpts.size() << '\n';
    vector<int> colours(sw.allpts.size(), -1);
    for(int i = 0; i < sw.allpts.size(); ++i) {
        int taken = 0;
        int k = sw.index[sw.allpts[i]];
        assert(prvs[k].size() <= 2);
        for(int j = 0; j < prvs[k].size(); ++j) {
            int x = prvs[k][j].first;
            int l = prvs[k][j].second;
            int y = colours[x];
            assert(y != -1);
            if(l != sw.s1[x]) y = 2 - y;
            if(l != sw.s1[k]) y = 2 - y;
            taken |= 1 << y;
        }
        int c = 0;
        while(taken & (1 << c)) c++;
        colours[k] = c;
        assert(c < 3);
    }
    for(int i = 0; i < sw.index.size(); ++i) {
        cout << sw.s1[i] + 1 << ' ';
        cout << sw.s2[i] + 1 << ' ';
        cout << "ryg"[colours[i]] << ' ';
        cout << "ryg"[2 - colours[i]] << '\n';
    }
}


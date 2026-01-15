#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<functional>
using namespace std;
typedef pair<int,int> ii;

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}


template <typename T> struct fraction {
    T p, q;
    T gcd(T a, T b) { return b == T(0) ? a : gcd(b, a % b); }
    T my_abs(T a) { return a < T(0) ? -a : a; }
    fraction() : p(T(0)), q(T(1)) { }
    fraction(T _p) : p(_p), q(T(1)) { }
    fraction(T _p, T _q) : p(_p), q(_q) {
        reduce();
    }
    void reduce() {
        if(p == T(0)) {
            q = T(1);
            return;
        }
        assert(q != T(0));
        if(q < T(0)) {
            p = -p;
            q = -q;
        }
        T g = gcd(my_abs(q), my_abs(p));
        p /= g;
        q /= g;
    }
    fraction<T> operator +(const fraction& o) {
        return fraction<T>(p * o.q + q * o.p, q * o.q);
    }
    fraction<T> operator -(const fraction& o) {
        return fraction<T>(p * o.q - q * o.p, q * o.q);
    }
    fraction<T> operator *(const fraction& o) {
        return fraction<T>(p * o.p, q * o.q);
    }
    fraction<T> operator /(const fraction& o) {
        return fraction<T>(p * o.q, q * o.p);
    }
    fraction<T> operator -() {
        return fraction<T>(-p, q);
    }
    fraction<T>& operator +=(const fraction& o) {
        p *= o.q;
        p += q * o.p;
        q *= o.q;
        reduce();
        return *this;
    }
    fraction<T>& operator -=(const fraction& o) {
        p *= o.q;
        p -= q * o.p;
        q *= o.q;
        reduce();
        return *this;
    }
    fraction<T>& operator *=(const fraction& o) {
        p *= o.p;
        q *= o.q;
        reduce();
        return *this;
    }
    fraction<T>& operator /=(const fraction& o) {
        p *= o.q;
        q *= o.p;
        reduce();
        return *this;
    }
    friend bool operator ==(const fraction<T>& l, const fraction<T>& r) {
        return l.p == r.p && l.q == r.q;
    }
    friend bool operator !=(const fraction<T>& l, const fraction<T>& r) {
        return l.p != r.p || l.q != r.q;
    }
    friend bool operator <(const fraction<T>& l, const fraction<T>& r) {
        return l.p * r.q < r.p * l.q;
    }
    friend bool operator >(const fraction<T>& l, const fraction<T>& r) {
        return l.p * r.q > r.p * l.q;
    }
    friend std::ostream& operator <<(std::ostream& out, const fraction<T>& o) {
        out << o.p << '/' << o.q;
        return out;
    }
    friend fraction<T> abs(const fraction<T>& x) {
        return x < 0 ? -x : x;
    }
};

typedef fraction<__int128> coord;
typedef pair<coord, coord> point;

ostream& operator<<(ostream& dest, point &p) {
    dest << '(' << p.first << ", " << p.second << ')';
    return dest;
}

const point DUMMY = make_pair(coord(1'000'000'000, 1), coord(1'000'000'000, 1));

point intersect(__int128 x1, __int128 y1, __int128 x2, __int128 y2,
    __int128 x3, __int128 y3, __int128 x4, __int128 y4) {
    if(x1 == x3 && y1 == y3)
        return make_pair(coord(x1, 1), coord(y1, 1));
    if(x1 == x4 && y1 == y4)
        return make_pair(coord(x1, 1), coord(y1, 1));
    if(x2 == x3 && y2 == y3)
        return make_pair(coord(x2, 1), coord(y2, 1));
    if(x2 == x4 && y2 == y4)
        return make_pair(coord(x2, 1), coord(y2, 1));
    __int128 m = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if(m == 0) return DUMMY;
    __int128 d1 = x1 * y2 - y1 * x2, d2 = x3 * y4 - y3 * x4;
    __int128 n1 = d1 * (x3 - x4) - (x1 - x2) * d2;
    __int128 n2 = d1 * (y3 - y4) - (y1 - y2) * d2;
    coord c1(n1, m), c2(n2, m);
    if(c1 < min(x1, x2) || c1 > max(x1, x2))
        return DUMMY;
    if(c2 < min(y1, y2) || c2 > max(y1, y2))
        return DUMMY;
    if(c1 < min(x3, x4) || c1 > max(x3, x4))
        return DUMMY;
    if(c2 < min(y3, y4) || c2 > max(y3, y4))
        return DUMMY;
    return make_pair(coord(n1, m), coord(n2, m));
}

struct event {
    point p;
    int i1, i2, type;

    event(point _p, int _t, int _i1, int _i2) : p(_p), i1(_i1), i2(_i2), type(_t) { }

    friend bool operator <(const event &e, const event &f) {
        return tie(e.p, e.type) < tie(f.p, f.type);
    }
    friend bool operator >(const event &e, const event &f) {
        return tie(e.p, e.type) > tie(f.p, f.type);
    }
};

coord cross(point a, point b) {
    return a.first * b.second - a.second * b.first;
}

coord ccw(point a, point b, point c) {
    point ba(b.first - a.first, b.second - a.second);
    point cb(c.first - b.first, c.second - b.second);
    return cross(ba, cb);
}

typedef set<int>::iterator sl_it;

struct sweeper {
    priority_queue<event, vector<event>, greater<event>> pq;
    function<int(const int &a, const int &b)> sweep_cmp;
    set<int, decltype(sweep_cmp)> sl;
    set<pair<int,int>> sected;
    vector<sl_it> sl_loc;
    map<point, int> index;
    vector<vector<point>> sects;
    vector<point> allpts;
    vector<int> x1, y1, x2, y2, s1, s2;
    int n;

    point x_sweep = pair(coord(-1000000, 1), coord(0, 1));

    sweeper(vector<int> _x1, vector<int> _y1, 
        vector<int> _x2, vector<int> _y2) :
            x1(_x1), y1(_y1), x2(_x2), y2(_y2) {
        n = x1.size();
        sects.resize(n);
        sl_loc.resize(n);

        sweep_cmp = [&](const int &a, const int &b) {
            point sect1, sect2;
            if(x1[a] != x2[a]) {
                coord slope = (y2[a] - y1[a]);
                slope /= (x2[a] - x1[a]);
                coord sect1y = coord(y1[a]) + (x_sweep.first - x1[a]) * slope;
                sect1 = point(x_sweep.first, sect1y);
            } else {
                sect1 = x_sweep;
            }
            if(x1[b] != x2[b]) {
                coord slope = (y2[b] - y1[b]);
                slope /= (x2[b] - x1[b]);
                coord sect2y = coord(y1[b]) + (x_sweep.first - x1[b]) * slope;
                sect2 = point(x_sweep.first, sect2y);
            } else {
                sect2 = x_sweep;
            }
            if(sect1 == sect2) {
                if(x1[a] == x2[a] && x1[b] == x2[b]) {
                    return y1[a] < y1[b];
                }
                if(x1[a] == x2[a]) {
                    return false;
                }
                if(x1[b] == x2[b]) {
                    return true;
                }
                coord slope1 = (y2[a] - y1[a]);
                slope1 /= (x2[a] - x1[a]);
                coord slope2 = (y2[b] - y1[b]);
                slope2 /= (x2[b] - x1[b]);
                if(slope1 == slope2)
                    return tie(x1[a], y1[a]) < tie(x1[b], y1[b]);
                return slope1 < slope2;
            }
            return sect1 < sect2;
        };

        sl = set<int, decltype(sweep_cmp)>(sweep_cmp);
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
            if(sect < x_sweep) continue;
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
        sort(sw.sects[i].begin(), sw.sects[i].end());
        for(int j = 1; j < sw.sects[i].size(); ++j) {
            prvs[sw.index[sw.sects[i][j]]].emplace_back(sw.index[sw.sects[i][j - 1]], i);
        }
    }
    sort(sw.allpts.begin(), sw.allpts.end());
    assert(sw.allpts.size() <= 200000);
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

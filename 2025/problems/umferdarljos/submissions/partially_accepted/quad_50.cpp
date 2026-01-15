#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<map>
#include<cassert>
#include<algorithm>
using namespace std;

template <class T>
constexpr T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }

template <class T>
struct fraction
{
    T n, d;
    constexpr fraction(T n_ = T(0), T d_ = T(1)) : n(n_), d(d_)
    {
        assert(d_ != 0);
        if (d < T(0))
            n = -n, d = -d;
        T g = gcd(n < 0 ? -n : n, d < 0 ? -d : d);
        n /= g, d /= g;
    }
    constexpr fraction(const fraction<T> &other)
        : n(other.n), d(other.d) {}
    constexpr fraction<T> operator-() const
    {
        return {-n, d};
    }
    constexpr fraction<T> operator+(const fraction<T> &other) const
    {
        return {n * other.d + other.n * d, d * other.d};
    }
    constexpr fraction<T> operator-(const fraction<T> &other) const
    {
        return {n * other.d - other.n * d, d * other.d};
    }
    constexpr fraction<T> operator*(const fraction<T> &other) const
    {
        return {n * other.n, d * other.d};
    }
    constexpr fraction<T> operator/(const fraction<T> &other) const
    {
        return {n * other.d, d * other.n};
    }
    constexpr fraction<T> operator+=(const fraction<T> &other)
    {
        return *this = {n * other.d + other.n * d,
                        d * other.d};
    }
    constexpr fraction<T> operator-=(const fraction<T> &other)
    {
        return *this = {n * other.d - other.n * d,
                        d * other.d};
    }
    constexpr fraction<T> operator*=(const fraction<T> &other)
    {
        return *this = {n * other.n, d * other.d};
    }
    constexpr fraction<T> operator/=(const fraction<T> &other)
    {
        return *this = {n * other.d, d * other.n};
    }
    constexpr bool operator<(const fraction<T> &other) const
    {
        return n * other.d < other.n * d;
    }
    constexpr bool operator<=(const fraction<T> &other) const
    {
        return !(other < *this);
    }
    constexpr bool operator>(const fraction<T> &other) const
    {
        return other < *this;
    }
    constexpr bool operator>=(const fraction<T> &other) const
    {
        return !(*this < other);
    }
    constexpr bool operator==(const fraction<T> &other) const
    {
        return n == other.n && d == other.d;
    }
    constexpr bool operator!=(const fraction<T> &other) const
    {
        return !(*this == other);
    }
};

template <typename T>
constexpr fraction<T> abs(const fraction<T> &f)
{
    return {f.n < 0 ? -f.n : f.n, f.d};
}

template <typename T>
std::istream &operator>>(std::istream &ins, fraction<T> &x)
{
    T n, d{T(1)};
    ins >> n;
    x = {n, d};
    return ins;
}

template <typename T>
std::ostream &operator<<(std::ostream &outs, const fraction<T> x)
{
    outs << "(" << x.n << "/" << x.d << ")";
    return outs;
}

typedef fraction<__int128> coord;
typedef pair<coord,coord> point;
point dummy = make_pair(coord(1'000'000'000, 1), coord(1'000'000'000, 1));

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
    if(m == 0) return dummy;
    coord c1(n1, m), c2(n2, m);
    if(c1 < min(x1, x2) || c1 > max(x1, x2))
        return dummy;
    if(c2 < min(y1, y2) || c2 > max(y1, y2))
        return dummy;
    if(c1 < min(x3, x4) || c1 > max(x3, x4))
        return dummy;
    if(c2 < min(y3, y4) || c2 > max(y3, y4))
        return dummy;
    return make_pair(coord(n1, m), coord(n2, m));
}

int main() {
    int n; cin >> n;
    vector<int> x1(n), y1(n), x2(n), y2(n);
    for(int i = 0; i < n; ++i) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }
    map<point, int> index;
    vector<int> s1, s2;
    vector<vector<point>> sects(n);
    vector<point> allpts;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            point p = intersect(x1[i], y1[i], x2[i], y2[i], x1[j], y1[j], x2[j], y2[j]);
            if(p == dummy) continue;
            if(!index.count(p)) {
                int x = index.size();
                index[p] = x;
                s1.push_back(i);
                s2.push_back(j);
                allpts.push_back(p);
            }
            sects[i].push_back(p);
            sects[j].push_back(p);

        }
    }
    vector<vector<pair<int,int>>> prvs(index.size());
    for(int i = 0; i < n; ++i) {
        sort(sects[i].begin(), sects[i].end());
        for(int j = 1; j < sects[i].size(); ++j) {
            prvs[index[sects[i][j]]].emplace_back(index[sects[i][j - 1]], i);
        }
    }
    sort(allpts.begin(), allpts.end());
    cout << allpts.size() << '\n';
    vector<int> colours(allpts.size(), -1);
    for(int i = 0; i < allpts.size(); ++i) {
        int taken = 0;
        int k = index[allpts[i]];
        assert(prvs[k].size() <= 2);
        for(int j = 0; j < prvs[k].size(); ++j) {
            int x = prvs[k][j].first;
            int l = prvs[k][j].second;
            int y = colours[x];
            assert(y != -1);
            if(l != s1[x]) y = 2 - y;
            if(l != s1[k]) y = 2 - y;
            taken |= 1 << y;
        }
        int c = 0;
        while(taken & (1 << c)) c++;
        colours[k] = c;
        assert(c < 3);
    }
    for(int i = 0; i < index.size(); ++i) {
        cout << s1[i] + 1 << ' ';
        cout << s2[i] + 1 << ' ';
        cout << "ryg"[colours[i]] << ' ';
        cout << "ryg"[2 - colours[i]] << '\n';
    }
}

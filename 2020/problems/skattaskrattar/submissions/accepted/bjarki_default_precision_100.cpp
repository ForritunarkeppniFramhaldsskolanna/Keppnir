#include <bits/stdc++.h>
using namespace std;
//template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct frac {
    ll x, y;
    frac(ll x = 0, ll y = 1) : x(x), y(y) {
        assert(y != 0);
        ll g = gcd(abs(x),abs(y));
        this->x /= g;
        this->y /= g;
        if (this->y < 0) {
            this->x = -this->x;
            this->y = -this->y;
        }
    }
    frac operator +(const frac &other) const {
        return frac(x * other.y + y * other.x, y * other.y);
    }
    frac operator -(const frac &other) const {
        return frac(x * other.y - y * other.x, y * other.y);
    }
    frac operator *(const frac &other) const {
        return frac(x * other.x, y * other.y);
    }
    frac operator /(const frac &other) const {
        return frac(x * other.y, y * other.x);
    }
    bool operator ==(const frac &other) const {
        return x * other.y == y * other.x;
    }
    bool operator <(const frac &other) const {
        return x * other.y < y * other.x;
    }
    bool operator <=(const frac &other) const {
        return x * other.y <= y * other.x;
    }
    bool operator >=(const frac &other) const {
        return x * other.y >= y * other.x;
    }
};
ostream& operator <<(ostream &outs, const frac &f) {
    return outs << 1.0 * f.x / f.y;
}

struct line {
    frac a, b;
    line(frac a, frac b) : a(a), b(b) {
    }
    frac eval(frac x) const {
        return a * x + b;
    }
    bool intersect(const line &other, frac &x) const {
        if (a == other.a) {
            return false;
        }

        x = (other.b - b) / (a - other.a);
        return true;
    }
};

vector<pair<frac, line> > read_lines(int n) {
    frac start, acc;
    vector<pair<frac, line> > line1;
    rep(i,0,n-1) {
        ll pi, ai;
        cin >> pi >> ai;
        frac p(pi,100), a(ai);
        line1.push_back(make_pair(start, line(p, acc - p * start)));
        acc = acc + p * (a - start);
        start = a;
    }
    ll tmp;
    cin >> tmp;
    frac pp(tmp,100);
    line1.push_back(make_pair(start, line(pp, acc - pp * start)));
    return line1;
}

frac eval(const vector<pair<frac,line> > &lines, frac x) {
    int lo = 0,
        hi = (int)lines.size() - 1,
        res = -1;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (lines[mid].first <= x) {
            lo = mid+1;
            res = mid;
        } else {
            hi = mid-1;
        }
    }
    assert(res >= 0);
    return lines[res].second.eval(x);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<frac,line> > line1 = read_lines(n),
                             line2 = read_lines(m);

    set<frac> S;
    iter(it,line1) {
        frac x = it->first;
        if (eval(line1, x) == eval(line2, x)) {
            S.insert(x);
        }
    }
    iter(it,line2) {
        frac x = it->first;
        if (eval(line1, x) == eval(line2, x)) {
            S.insert(x);
        }
    }

    int i = 0,
        j = 0;

    while (true) {
        frac x;
        if (line1[i].second.intersect(line2[j].second, x)) {
            bool ok = true;
            if (x < line1[i].first) ok = false;
            if (x < line2[j].first) ok = false;
            if (i+1 < line1.size() && x >= line1[i+1].first) ok = false;
            if (j+1 < line2.size() && x >= line2[j+1].first) ok = false;

            if (ok) {
                S.insert(x);
            }
        }

        if (i+1 == line1.size() && j+1 == line2.size()) {
            break;
        }
        if (i+1 == line1.size()) {
            j++;
            continue;
        }
        if (j+1 == line2.size()) {
            i++;
            continue;
        }

        if (line1[i+1].first < line2[j+1].first) {
            i++;
        } else {
            j++;
        }
    }

    iter(it,S) {
        cout << *it << endl;
    }

    return 0;
}


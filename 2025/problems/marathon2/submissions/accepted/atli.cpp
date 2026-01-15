#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

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

const int FINISH = 42195;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x, y, h, s;
    cin >> n >> x >> y >> h >> s;
    vector<int> locs(n + 2, 0);
    for(int i = 0; i < n; ++i)
        cin >> locs[i + 1];
    locs.back() = FINISH;
    sort(locs.begin(), locs.end());
    locs.erase(unique(locs.begin(), locs.end()), locs.end());
    n = locs.size();
    vector<fraction<ll>> dp(n, 0);
    for(int i = n - 1; i >= 0; --i) {
        if(locs[i] + x >= FINISH) {
            dp[i] = fraction<ll>(FINISH - locs[i], h);
        } else {
            ll slowdist = FINISH - locs[i] - x;
            fraction<ll> slowtime = fraction<ll>(slowdist, s);
            fraction<ll> fasttime = fraction<ll>(x, h);
            dp[i] = slowtime + fasttime;
        }
        auto it = lower_bound(locs.begin(), locs.end(), locs[i] + x);
        int j = distance(locs.begin(), it);
        if(j < n) {
            ll slowdist = locs[j] - locs[i] - x;
            fraction<ll> slowtime = fraction<ll>(slowdist, s);
            fraction<ll> fasttime = fraction<ll>(x, h);
            fraction<ll> time = slowtime + fasttime;
            dp[i] = min(dp[i], dp[j] + time + y);
        }
        if(j > 0) {
            ll dist = locs[j - 1] - locs[i];
            fraction<ll> fasttime = fraction<ll>(dist, h);
            dp[i] = min(dp[i], dp[j - 1] + fasttime + y); 
        }
    }
    ll ans = dp[0].p / dp[0].q;
    ll ansh = ans / 3600, ansm = (ans % 3600) / 60, anss = ans % 60;
    if(ansh < 10) cout << '0';
    cout << ansh;
    cout << ':';
    if(ansm < 10) cout << '0';
    cout << ansm;
    cout << ':';
    if(anss < 10) cout << '0';
    cout << anss;
    cout << '\n';
}

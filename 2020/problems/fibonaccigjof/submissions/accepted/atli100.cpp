#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i = (a); i < (b); ++i)
const ll mod = 1000000007;

struct mat2x2 {
    ll a, b, c, d;
    mat2x2() : a(0), b(0), c(0), d(0) {}
    mat2x2(ll _a, ll _b, ll _c, ll _d) : a(_a), b(_b), c(_c), d(_d) {}
    mat2x2(const mat2x2& o) : a(o.a), b(o.b), c(o.c), d(o.d) {}
    mat2x2 operator*(const mat2x2 &o) {
        ll _a = a * o.a + b * o.c;
        ll _b = a * o.b + b * o.d;
        ll _c = c * o.a + d * o.c;
        ll _d = c * o.b + d * o.d;
        _a %= mod; _b %= mod; _c %= mod; _d %= mod;
        return mat2x2(_a, _b, _c, _d);
    }
    mat2x2 operator+(const mat2x2 &o) {
        ll _a = (a + o.a) % mod;
        ll _b = (b + o.b) % mod;
        ll _c = (c + o.c) % mod;
        ll _d = (d + o.d) % mod;
        return mat2x2(_a, _b, _c, _d);
    }
    mat2x2 pow(ll n) {
        mat2x2 res(1, 0, 0, 1);
        mat2x2 base(*this);
        while(n) {
            if(n & 1) res = res * base;
            base = base * base;
            n >>= 1;
        }
        return res;
    }
};

mat2x2 ze() { return mat2x2(0, 0, 0, 0); }
mat2x2 id() { return mat2x2(1, 0, 0, 1); }
mat2x2 fm() { return mat2x2(1, 1, 1, 0); }

struct node {
  int l, r;
  mat2x2 x, lazy;
  node() : x(ze()), lazy(id()) {}
  node(int _l, int _r) : l(_l), r(_r), x(ze()), lazy(id()) { }
  node(int _l, int _r, mat2x2 _x) : node(_l,_r) { x = _x; }
  node(node a, node b) : node(a.l,b.r) { x = a.x + b.x; }
  void range_update(mat2x2 d) { lazy = d; }
  void apply() { x = lazy * x; lazy = id(); }
  void push(node &u) { u.lazy = lazy * u.lazy; } };

struct segment_tree {
  int n;
  vector<node> arr;
  segment_tree() { }
  segment_tree(const vector<mat2x2> &a) : n(a.size()), arr(4*n) {
    mk(a,0,0,n-1); }
  node mk(const vector<mat2x2> &a, int i, int l, int r) {
    int m = (l+r)/2;
    return arr[i] = l > r ? node(l,r) :
      l == r ? node(l,r,a[l]) :
      node(mk(a,2*i+1,l,m),mk(a,2*i+2,m+1,r)); }
  node query(int l, int r, int i=0) {
    propagate(i);
    int hl = arr[i].l, hr = arr[i].r;
    if (r < hl || hr < l) return node(hl,hr);
    if (l <= hl && hr <= r) return arr[i];
    return node(query(l,r,2*i+1),query(l,r,2*i+2)); }
  node range_update(int l, int r, mat2x2 v, int i=0) {
    propagate(i);
    int hl = arr[i].l, hr = arr[i].r;
    if (r < hl || hr < l) return arr[i];
    if (l <= hl && hr <= r)
      return arr[i].range_update(v), propagate(i), arr[i];
    return arr[i] = node(range_update(l,r,v,2*i+1),
                         range_update(l,r,v,2*i+2)); }
  void propagate(int i) {
    if (arr[i].l < arr[i].r)
      arr[i].push(arr[2*i+1]), arr[i].push(arr[2*i+2]);
    arr[i].apply(); } };

int main() {
    ios_base::sync_with_stdio(false);
    ll n, m, t, l, r, d; cin >> n >> m;
    vector<mat2x2> x(n);
    rep(i,0,n) {
        cin >> d;
        x[i] = fm().pow(d - 1);
    }
    segment_tree st(x);
    while(m--) {
        cin >> t >> l >> r;
        if(t == 1) {
            cin >> d;
            st.range_update(l - 1, r - 1, fm().pow(d));
        } else {
            cout << st.query(l - 1, r - 1).x.a << '\n';
        }
    }
}



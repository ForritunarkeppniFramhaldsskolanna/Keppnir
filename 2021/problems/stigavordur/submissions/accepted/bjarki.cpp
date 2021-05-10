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

#ifndef STNODE
#define STNODE
struct node {
  int l, r;
  ll x, lazy;
  node() {}
  node(int _l, int _r) : l(_l), r(_r), x(0), lazy(0) { }
  node(int _l, int _r, ll _x) : node(_l,_r) { x = _x; }
  node(node a, node b) : node(a.l,b.r) { x = gcd(a.x, b.x); }
  void update(ll v) { x = v; }
};
#endif
struct segment_tree {
  int n;
  vector<node> arr;
  segment_tree() { }
  segment_tree(const vector<ll> &a) : n(a.size()), arr(4*n) {
    mk(a,0,0,n-1); }
  node mk(const vector<ll> &a, int i, int l, int r) {
    int m = (l+r)/2;
    return arr[i] = l > r ? node(l,r) :
      l == r ? node(l,r,a[l]) :
      node(mk(a,2*i+1,l,m),mk(a,2*i+2,m+1,r)); }
  node update(int at, ll v, int i=0) {
    int hl = arr[i].l, hr = arr[i].r;
    if (at < hl || hr < at) return arr[i];
    if (hl == at && at == hr) {
      arr[i].update(v); return arr[i]; }
    return arr[i] =
      node(update(at,v,2*i+1),update(at,v,2*i+2)); }
  node query(int l, int r, int i=0) {
    int hl = arr[i].l, hr = arr[i].r;
    if (r < hl || hr < l) return node(hl,hr);
    if (l <= hl && hr <= r) return arr[i];
    return node(query(l,r,2*i+1),query(l,r,2*i+2)); }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> arr(n);
    rep(i,0,n) cin >> arr[i];
    segment_tree st(arr);
    rep(i,0,m) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            a--;
            st.update(a,b);
        } else {
            a--, b--;
            cout << st.query(a,b).x << endl;
        }
    }

    return 0;
}


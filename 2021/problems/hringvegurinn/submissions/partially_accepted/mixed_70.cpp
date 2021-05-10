#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
  int l, r;
  ll x, lazy;
  node() {}
  node(int _l, int _r) : l(_l), r(_r), x(0), lazy(0) { }
  node(int _l, int _r, ll _x) : node(_l,_r) { x = _x; }
  node(node a, node b) : node(a.l,b.r) { x = a.x + b.x; }
  void update(ll v) { x = v; }
  void range_update(ll v) { lazy = v; }
  void apply() { x += lazy * (r - l + 1); lazy = 0; }
  void push(node &u) { u.lazy += lazy; } };

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
    propagate(i);
    int hl = arr[i].l, hr = arr[i].r;
    if (at < hl || hr < at) return arr[i];
    if (hl == at && at == hr) {
      arr[i].update(v); return arr[i]; }
    return arr[i] =
      node(update(at,v,2*i+1),update(at,v,2*i+2)); }
  node query(int l, int r, int i=0) {
    propagate(i);
    int hl = arr[i].l, hr = arr[i].r;
    if (r < hl || hr < l) return node(hl,hr);
    if (l <= hl && hr <= r) return arr[i];
    return node(query(l,r,2*i+1),query(l,r,2*i+2)); }
  node range_update(int l, int r, ll v, int i=0) {
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
    int n, q, x, l, r, o; 
    cin >> n >> q;
    if(n <= 1000) {
        vector<ll> c(n, 0);
        while(q--) {
            cin >> o;
            if(o == 1) {
                cin >> x;
                vector<ll> c2 = c;
                for(int i = 0; i < n; ++i) c[i] = c2[(i + x) % n];
            } else if(o == 2) {
                cin >> l >> r >> x;
                l--; r--;
                int p = l;
                while(true) {
                    c[p] += x;
                    if(p == r) break;
                    p++;
                    if(p == n) p = 0;
                }
            } else if(o == 3) {
                cin >> l >> r;
                l--; r--;
                ll res = 0;
                int p = l;
                while(true) {
                    res += c[p];
                    if(p == r) break;
                    p++;
                    if(p == n) p = 0;
                }
                cout << res << '\n';
            }
        }
    } else {
        vector<ll> empt(n, 0);
        segment_tree sg(empt);
        while(q--) {
            cin >> o >> l >> r;
            l--; r--;
            if(o == 2) cin >> x, sg.range_update(l, r, x);
            if(o == 3) cout << sg.query(l, r).x << '\n';
        }
    }
}


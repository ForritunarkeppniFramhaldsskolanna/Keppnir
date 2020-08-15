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

ll MOD = 1000000007;

// template <class K> bool eq(K a, K b) { return a == b; }
// template <class T> struct matrix {
//   int rows, cols, cnt; ll data[4];
//   inline T& at(int i, int j) { return data[i * cols + j]; }
//   matrix(int r=2, int c=2) : rows(r), cols(c), cnt(r * c) {
//       rep(i,0,4) data[i] = T(0);
//   }
//   matrix(const matrix& other) : rows(other.rows),
//     cols(other.cols), cnt(other.cnt) { 
//         rep(i,0,4) {
//             data[i] = other.data[i];
//         }
//     }
//   T& operator()(int i, int j) { return at(i, j); }
//   matrix<T> operator +(const matrix& other) {
//       matrix<T> res(*this); rep(i,0,cnt) {
//           res.data[i] += other.data[i];
//           res.data[i] %= MOD;
//       }
//     return res;
//   }
//   matrix<T> operator *(T other) {
//     matrix<T> res(*this);
//     rep(i,0,cnt) res.data[i] *= other; return res; }
//   matrix<T> operator *(const matrix& other) {
//     matrix<T> res(rows, other.cols);
//     rep(i,0,rows) rep(k,0,cols) rep(j,0,other.cols) {
//       res(i, j) += at(i, k) * other.data[k * other.cols + j] % MOD;
//       res(i, j) %= MOD;
//     }
//     return res; }
//   matrix<T> pow(ll p) {
//     matrix<T> res(rows, cols), sq(*this);
//     rep(i,0,rows) res(i, i) = T(1);
//     while (p) {
//       if (p & 1) res = res * sq;
//       p >>= 1;
//       if (p) sq = sq * sq;
//     } return res; }
// };

template <class T>
struct matrix {
    ll a, b, c, d;
    // matrix() {
    //     a = 0;
    //     b = 0;
    //     c = 0;
    //     d = 0;
    // }

    matrix operator *(const matrix &other) const {
        matrix res;
        res.a = (a * other.a + b * other.c) % MOD;
        res.b = (a * other.b + b * other.d) % MOD;
        res.c = (c * other.a + d * other.c) % MOD;
        res.d = (c * other.b + d * other.d) % MOD;
        return res;
    }

    matrix operator +(const matrix &other) const {
        matrix res;
        res.a = (a + other.a) % MOD;
        res.b = (b + other.b) % MOD;
        res.c = (c + other.c) % MOD;
        res.d = (d + other.d) % MOD;
        return res;
    }
};

matrix<ll> FIB;
matrix<ll> pows[60];

#ifndef STNODE
#define STNODE
struct node {
  int l, r;
  matrix<ll> x, lazy;
  node() {
      x.a = 0;
      x.b = 0;
      x.c = 0;
      x.d = 0;

      lazy.a = 1;
      lazy.b = 0;
      lazy.c = 0;
      lazy.d = 1;
  }
  node(int _l, int _r) : l(_l), r(_r) {
      x.a = 0;
      x.b = 0;
      x.c = 0;
      x.d = 0;

      lazy.a = 1;
      lazy.b = 0;
      lazy.c = 0;
      lazy.d = 1;
  }
  node(int _l, int _r, matrix<ll> _x) : node(_l,_r) { x = _x; }
  node(node a, node b) : node(a.l,b.r) { x = a.x + b.x; }
  void range_update(matrix<ll> v) {
      lazy = v;
  }
  void apply() {
      // for (int i = 0; i < 60; i++) {
      //     if (lazy & (1LL<<i)) {
      //         x = x * pows[i];
      //     }
      // }
      x = x * lazy;
      lazy.a = 1;
      lazy.b = 0;
      lazy.c = 0;
      lazy.d = 1;

      // lazy = 0;
  }
  void push(node &u) {
      u.lazy = u.lazy * lazy;
  }
};
#endif
// vim: cc=60 ts=2 sts=2 sw=2:
struct segment_tree {
  int n;
  vector<node> arr;
  segment_tree() { }
  segment_tree(const vector<matrix<ll> > &a) : n(a.size()), arr(4*n) {
    mk(a,0,0,n-1); }
  node mk(const vector<matrix<ll> > &a, int i, int l, int r) {
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
  node range_update(int l, int r, matrix<ll> v, int i=0) {
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
// vim: cc=60 ts=2 sts=2 sw=2:

int main() {
    FIB.a = 0;
    FIB.b = 1;
    FIB.c = 1;
    FIB.d = 1;

    pows[0] = FIB;
    for (int i = 1; i < 60; i++) {
        pows[i] = pows[i-1] * pows[i-1];
    }

    // rep(i,0,60) {
    //     cout << pows[i].a << " " << pows[i].b << endl;
    //     cout << pows[i].c << " " << pows[i].d << endl;
    //     cout << endl;
    // }

    int n, m;
    cin >> n >> m;

    vector<matrix<ll> > arr(n);
    rep(i,0,n) {
        ll x;
        cin >> x;

        arr[i].a = 1;
        arr[i].b = 0;
        arr[i].c = 0;
        arr[i].d = 1;
        for (int j = 0; j < 60; j++) {
            if (x & (1LL << j)) {
                arr[i] = arr[i] * pows[j];
            }
        }
    }

    segment_tree st(arr);

    rep(i,0,m) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            ll d;
            cin >> l >> r >> d;

            matrix<ll> mat;
            mat.a = 1;
            mat.b = 0;
            mat.c = 0;
            mat.d = 1;
            for (int i = 0; i < 60; i++) {
                if (d & (1LL<<i)) {
                    mat = mat * pows[i];
                }
            }

            // rep(i,0,2) {
            //     rep(j,0,2) {
            //         cout << mat(i,j) << " ";
            //     }
            //     cout << endl;
            // }

            l--, r--;
            st.range_update(l, r, mat);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            matrix<ll> mat = st.query(l, r).x;
            cout << mat.c << endl;
        }

        // rep(i,0,2) {
        //     rep(j,0,n) {
        //         matrix<ll> mat = st.query(j,j).x;
        //         cout << mat(i,0) << " ";
        //         cout << mat(i,1) << " ";
        //         cout << "  ";
        //     }
        //     cout << endl;
        // }
    }

    return 0;
}


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

ll mod = 1000000007;

template <class K> bool eq(K a, K b) { return a == b; }
template <class T> struct matrix {
  int rows, cols, cnt; vector<T> data;
  inline T& at(int i, int j) { return data[i * cols + j]; }
  matrix(int r, int c) : rows(r), cols(c), cnt(r * c) {
    data.assign(cnt, T(0)); }
  matrix(const matrix& other) : rows(other.rows),
    cols(other.cols), cnt(other.cnt), data(other.data) { }
  T& operator()(int i, int j) { return at(i, j); }
  matrix<T> operator +(const matrix& other) {
    matrix<T> res(*this); rep(i,0,cnt)
      res.data[i] += other.data[i]; return res; }
  matrix<T> operator -(const matrix& other) {
    matrix<T> res(*this); rep(i,0,cnt)
      res.data[i] -= other.data[i]; return res; }
  matrix<T> operator *(T other) {
    matrix<T> res(*this);
    rep(i,0,cnt) res.data[i] *= other; return res; }
  matrix<T> operator *(const matrix& other) {
    matrix<T> res(rows, other.cols);
    rep(i,0,rows) rep(k,0,cols) rep(j,0,other.cols) {
      res(i, j) += at(i, k) * other.data[k * other.cols + j] % mod;
      res(i, j) %= mod;
    }
    return res; }
  matrix<T> pow(ll p) {
    matrix<T> res(rows, cols), sq(*this);
    rep(i,0,rows) res(i, i) = T(1);
    while (p) {
      if (p & 1) res = res * sq;
      p >>= 1;
      if (p) sq = sq * sq;
    } return res; }
  matrix<T> rref(T &det, int &rank) {
    matrix<T> mat(*this); det = T(1), rank = 0;
    for (int r = 0, c = 0; c < cols; c++) {
      int k = r;
      rep(i,k+1,rows) if (abs(mat(i,c)) > abs(mat(k,c))) k = i;
      if (k >= rows || eq<T>(mat(k, c), T(0))) continue;
      if (k != r) {
        det *= T(-1);
        rep(i,0,cols) swap(mat.at(k, i), mat.at(r, i));
      } det *= mat(r, r); rank++;
      T d = mat(r,c);
      rep(i,0,cols) mat(r, i) /= d;
      rep(i,0,rows) {
        T m = mat(i, c);
        if (i != r && !eq<T>(m, T(0)))
          rep(j,0,cols) mat(i, j) -= m * mat(r, j);
      } r++;
    } return mat; }
  matrix<T> transpose() {
    matrix<T> res(cols, rows);
    rep(i,0,rows) rep(j,0,cols) res(j, i) = at(i, j);
    return res; } };
// vim: cc=60 ts=2 sts=2 sw=2:

ll fibonacci(ll n) {

    matrix<ll> mat(2,2);
    mat(0,0) = 0;
    mat(0,1) = 1;
    mat(1,0) = 1;
    mat(1,1) = 1;

    mat = mat.pow(n);
    return mat(1,0);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> arr(n);
    rep(i,0,n) {
        cin >> arr[i];
    }

    rep(i,0,m) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r; 
            ll d;
            cin >> l >> r >> d;
            l--, r--;
            rep(i,l,r+1) {
                arr[i] += d;
            }
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int sm = 0;
            rep(i,l,r+1) {
                sm += fibonacci(arr[i]);
                sm %= mod;
            }
            cout << sm << endl;
        }
    }

    return 0;
}


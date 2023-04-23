#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i = (a); i < (b); ++i)
typedef complex<long double> cpx;
void fft(cpx *x, int n, bool inv=false) {
  for(int i = 0, j = 0; i < n; i++) {
    if(i < j) swap(x[i], x[j]);
    int m = n >> 1;
    while(1 <= m && m <= j) {
      j -= m, m >>= 1;
    }
    j += m; }
  for(int mx = 1; mx < n; mx <<= 1) {
    cpx wp = polar(1.0L, (inv ? -1 : 1) * M_PIl / mx), w = 1;
    for(int m = 0; m < mx; m++, w *= wp) {
      for(int i = m; i < n; i += mx << 1) {
        cpx t = x[i + mx] * w; x[i + mx] = x[i] - t;
        x[i] += t; } } } if(inv) rep(i,0,n) x[i] /= n; }

const int mxsz = 262144;

cpx p[mxsz], q[mxsz];

int read_to(cpx *a) {
    int sz, x; cin >> sz;
    for(int i = 0; i < mxsz; ++i) a[i] = cpx(0);
    for(int i = 0; i < sz; ++i) cin >> x, a[x] += 1;
    fft(a, mxsz);
    return sz;
}

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    ll denom = read_to(p);
    for(int i = 1; i < n; ++i) {
        denom *= read_to(q);
        for(int j = 0; j < mxsz; ++j) p[j] *= q[j];
    }
    fft(p, mxsz, true);
    for(int i = 0; i < mxsz; ++i) {
        ll x = round(abs(p[i]));
        if(x == 0) continue;
        ll g = gcd(x, denom);
        cout << i << ' ' << x / g << '/' << denom / g << '\n';
    }
}

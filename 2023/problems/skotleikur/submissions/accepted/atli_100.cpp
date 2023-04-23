#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll egcd(ll a, ll b, ll& x, ll& y) {
  if (b == 0) { x = 1; y = 0; return a; }
  ll d = egcd(b, a % b, x, y);
  x -= a / b * y; swap(x, y); return d; }

void quit() {
    cout << "0\n";
    exit(0);
}

int main() {
    ll c, a, b, x0, y0;
    cin >> c >> a >> b;
    ll g = egcd(a, b, x0, y0);
    if(c % g != 0) quit();
    a /= g; b /= g;
    egcd(a, b, x0, y0);
    x0 *= c / g; y0 *= c / g;
    ll mnk = y0 / a, mxk = -x0 / b;
    if(mnk > mxk) swap(mnk, mxk);
    mnk--; mxk++;
    if(x0 + mnk * b < 0 || y0 - mnk * a < 0) mnk++;
    if(x0 + mxk * b < 0 || y0 - mxk * a < 0) mxk--;
    if(x0 + mnk * b < 0 || y0 - mnk * a < 0) mnk++;
    if(x0 + mxk * b < 0 || y0 - mxk * a < 0) mxk--;
    cout << max(0LL, mxk - mnk + 1) << '\n';
    for(ll k = mnk; k <= mxk; ++k) {
        cout << x0 + k * b << ' ' << y0 - k * a << '\n';
    }
}

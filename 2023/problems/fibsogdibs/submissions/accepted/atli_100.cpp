#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

struct mat2x2 {
    ll a, b, c, d;
    mat2x2(ll _a, ll _b, ll _c, ll _d) : a(_a % MOD), b(_b % MOD), c(_c % MOD), d(_d % MOD) { }
    mat2x2 operator*(const mat2x2& o) const {
        return mat2x2(a * o.a + b * o.c, a * o.b + b * o.d, c * o.a + d * o.c, c * o.b + d * o.d);
    }
    mat2x2 pow(ll e) {
        mat2x2 bs(a, b, c, d);
        mat2x2 res(1, 0, 0, 1);
        while(e) {
            if(e & 1) res = res * bs;
            bs = bs * bs;
            e >>= 1;
        }
        return res;
    }
};

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    mat2x2 fib(1, 1, 1, 2);
    mat2x2 fibn = fib.pow(n);
    ll ares = (fibn.a * a + fibn.b * b) % MOD;
    ll bres = (fibn.c * a + fibn.d * b) % MOD;
    cout << ares << ' ' << bres << endl;
}

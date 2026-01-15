#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef int64_t ml;
typedef vector<ml> vm;

vm mat_mul(vm &a, vm &b) {
    vm c(25, 0);
    for(int i = 0; i < 5; ++i)
        for(int k = 0; k < 5; ++k)
            for(int j = 0; j < 5; ++j)
                c[5 * i + j] += a[5 * i + k] * b[5 * k + j];
    return c;
}

vm mat_pow(vm &a, ll e) {
    vm res(25, 0), sq = a;
    for(int i = 0; i < 5; ++i)
        res[5 * i + i] = 1;
    while(e > 0) {
        if(e & 1) res = mat_mul(res, sq);
        e /= 2;
        if(e > 0)
            sq = mat_mul(sq, sq);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n; n /= 5;
    vm BASE({ 2, -1, 1, -2, 1,
              1, 0, 0, 0, 0,
              0, 1, 0, 0, 0,
              0, 0, 1, 0, 0,
              0, 0, 0, 1, 0 });
    vm RES = mat_pow(BASE, n);
    ml ans = 61 * RES[20] + 37 * RES[21] + 21 * RES[22] + 9 * RES[23] + RES[24];
    string outp = "";
    while(ans > 0) {
        outp.push_back((char) ((ans % 10) + '0'));
        ans /= 10;
    }
    reverse(outp.begin(), outp.end());
    cout << outp << '\n';
}

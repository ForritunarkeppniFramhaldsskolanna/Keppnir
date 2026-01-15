#include <iostream>
using namespace std;
typedef long long ll;

bool test(ll f, ll d, ll n) {
    ll sm = 0;
    for(int i = 0; i < d; ++i) {
        sm += f;
        f++;
    }
    return sm == n;
}

int main() {
    ll x; cin >> x;
    for(ll f = 1; f <= x; ++f) {
        for(ll d = 1; d <= x; ++d) {
            if(test(f, d, x)) {
                cout << f << ' ' << d << '\n';
            }
        }
    }
}


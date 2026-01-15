#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll x; cin >> x;
    for(ll f = 1; f <= x; ++f) {
        ll lo = 1, hi = x;
        while(hi >= lo) {
            ll md = lo + (hi - lo) / 2;
            ll chk = f * md + md * (md - 1) / 2 - x;
            if(chk == 0) {
                cout << f << ' ' << md << '\n';
                break;
            }
            if(chk < 0) lo = md + 1;
            else hi = md - 1;
        }
    }
}


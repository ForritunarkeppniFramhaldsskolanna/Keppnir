#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_sqr(ll x) {
    ll y = sqrt(x);
    return y * y == x;
}

ll cnt(ll n, ll d, ll g) {
    int res = 0;
    while(n > 0) {
        if(n % g == d) res++;
        n /= g;
    }
    return res;
}

int main() {
    ll n, d;
    cin >> n >> d;
    // Edge cases
    if(n == d) {
        cout << "1\n";
        return 0;
    }
    if(d > n) {
        cout << "0\n";
        return 0;
    }
    // Check up to cube root
    ll bst = 0;
    for(ll i = 2; (i - 2) * (i - 2) * (i - 2) <= n; ++i) {
        bst = max(bst, cnt(n, d, i));
    }
    // Check if (1, d) possible, i.e. n = g + d
    // g == n - d -> n - d > d -> n > 2d
    // No need to check if (x, d) possible, i.e. n = gx + d
    // Same but g == (n - d) / x, must have g > d so we have
    // (n - d) / x > d, so it's just strictly harder to satisfy
    if(n > 2 * d) {
        bst = max(bst, 1LL);
    }
    // Check if (d, d) possible, i.e. n = dg + d for some g
    // -> d divides n
    // n / d = g + 1
    // g = n / d - 1
    // -> n / d - 1 > d
    if(n % d == 0 && n / d - 1 > d) {
        bst = max(bst, 2LL);
    }
    // Left to check (i, d, d), (d, i, d), (d, d, i)
    // Always have g > d. Only need to check g > cuberoot(n).
    // Thus since first term xg^2 <= n we must have x < cuberoot(n).
    // So we can consider only i < cuberoot(n).
    for(ll i = 0; (i - 2) * (i - 2) * (i - 2) <= n; ++i) {
        // (i, d, d) -> ig^2 + dg + d - n = 0 -> g = (-d+-sqrt(d^2-4i(d-n)))/2i
        if(i > 0) {
            if(4 * i * (d - n) <= d * d && is_sqr(d * d - 4 * i * (d - n))) {
                ll num = -d + ((ll) sqrt(d * d - 4 * i * (d - n)));
                if(num % (2 * i) == 0 && num / (2 * i) > d) {
                    bst = max(bst, 2LL);
                }
            }
        }
        // (d, i, d) -> dg^2 + ig + d - n = 0 -> g = (-i+-sqrt(i^2-4*d*(d-n)))/2d
        if(4 * d * (d - n) <= i * i && is_sqr(i * i - 4 * d * (d - n))) {
            ll num = -i + ((ll) sqrt(i * i - 4 * d * (d - n)));
            if(num % (2 * d) == 0 && num / (2 * d) > d) {
                bst = max(bst, 2LL);
            }
        }
        // (d, d, i) -> dg^2 + dg + i - n = 0 -> g = (-d+-sqrt(d^2-4d(i-n)))/2d
        if(4 * d * (i - n) <= d * d && is_sqr(d * d - 4 * d * (i - n))) {
            ll num = -d + ((ll) sqrt(d * d - 4 * d * (i - n)));
            if(num % (2 * d)== 0 && num / (2 * d) > d) {
                bst = max(bst, 2LL);
            }
        }
    }
    // If we have some result with at least 4 digits then n = ag^3 + bg^2 + cg + z
    // with a, b, c, z >= 0. Thus n >= ag^3 >= g^3 so cuberoot(n) >= g.
    cout << bst << '\n';
}

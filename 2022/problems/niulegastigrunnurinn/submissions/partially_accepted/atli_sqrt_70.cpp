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
    // Check up to sqrt
    ll bst = 0;
    for(ll i = 2; (i - 2) * (i - 2) <= n; ++i) {
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
    // If we have some result with at least 3 digits then n = ag^2 + bg + c
    // with a, b, c >= 0. Thus n >= ag^2 >= g^2 so sqrt(n) >= g.
    cout << bst << '\n';
}

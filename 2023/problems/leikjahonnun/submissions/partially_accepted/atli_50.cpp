#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

vl convolve(vl &v, vl &w) {
    vl res(v.size() + w.size(), 0);
    for(int i = 0; i < v.size(); ++i) {
        for(int j = 0; j < w.size(); ++j) {
            res[i + j] += v[i] * w[j];
        }
    }
    return res;
}

vl read_vec(ll &denom) {
    int sz, x; cin >> sz;
    denom *= sz;
    vl inp;
    for(int i = 0; i < sz; ++i) {
        cin >> x;
        while(x >= inp.size()) inp.push_back(0);
        inp[x] += 1;
    }
    return inp;
}

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n; 
    ll denom = 1;
    vl cur = read_vec(denom);
    if(n > 1) {
        vl tmp = read_vec(denom);
        cur = convolve(cur, tmp);
    }
    for(int i = 0; i < cur.size(); ++i) {
        if(cur[i] == 0) continue;
        cout << i << ' ';
        ll g = gcd(cur[i], denom);
        cout << cur[i] / g << '/' << denom / g << '\n';
    }
}

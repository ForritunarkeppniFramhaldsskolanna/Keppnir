#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

int best(int x, vl h) {
    int n = h.size();
    int res = INT_MAX;
    int nonz = 0;
    for(int y : h) if(y != 0) nonz++;
    if(h[x] == 0) {
        return nonz + 1;
    } else if(nonz == 1) {
        return 1;
    }
    for(int i = 0; i < h.size(); ++i) {
        if(h[i] == 0) continue;
        for(int j = i + 1; j < h.size(); ++j) {
            if(h[j] == 0) continue;
            h[i]--; h[j]--;
            res = min(res, best(x, h));
            h[i]++; h[j]++;
        }
    }
    return res;
}

int main() {
    ll n, B;
    cin >> n >> B;
    if(n == 1) {
        cout << "1\n";
        return 0;
    }
    vl xs(n);
    for(int i = 0; i < n; ++i) {
        cin >> xs[i];
        xs[i] = (xs[i] + B - 1) / B;
    }
    for(int i = 0; i < n; ++i) {
        cout << best(i, xs) << ' ';
    }
    cout << '\n';
}

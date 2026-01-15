#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main() {
    ll n, T, lo = 1, hi = 1;
    cin >> n >> T;
    vector<ll> w(n);
    for(int i = 0; i < n; ++i)
        cin >> w[i], hi += w[i];
    sort(w.begin(), w.end());
    while(hi > lo) {
        ll written = 0, penalty = 0;
        ll md = lo + (hi - lo) / 2;
        for(ll wi : w) {
            written += wi;
            penalty += written / md;
        }
        if(penalty >= T) lo = md + 1;
        else hi = md;
    }
    cout << lo << '\n';
}

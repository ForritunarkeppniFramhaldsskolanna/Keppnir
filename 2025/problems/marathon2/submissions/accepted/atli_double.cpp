#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;

const int FINISH = 42195;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x, y, h, s;
    cin >> n >> x >> y >> h >> s;
    vector<int> locs(n + 2, 0);
    for(int i = 0; i < n; ++i)
        cin >> locs[i + 1];
    locs.back() = FINISH;
    sort(locs.begin(), locs.end());
    locs.erase(unique(locs.begin(), locs.end()), locs.end());
    n = locs.size();
    vector<double> dp(n, 0);
    for(int i = n - 1; i >= 0; --i) {
        if(locs[i] + x >= FINISH) {
            dp[i] = ((double) (FINISH - locs[i])) / h;
        } else {
            double slowdist = FINISH - locs[i] - x;
            double slowtime = slowdist / s;
            double fasttime = ((double) x) / h;
            dp[i] = slowtime + fasttime;
        }
        auto it = lower_bound(locs.begin(), locs.end(), locs[i] + x);
        int j = distance(locs.begin(), it);
        if(j < n) {
            double slowdist = locs[j] - locs[i] - x;
            double slowtime = slowdist / s;
            double fasttime = ((double) x) / h;
            double time = slowtime + fasttime;
            dp[i] = min(dp[i], dp[j] + time + y);
        }
        if(j > 0) {
            double dist = locs[j - 1] - locs[i];
            double fasttime = dist / h;
            dp[i] = min(dp[i], dp[j - 1] + fasttime + y); 
        }
    }
    ll ans = floor(dp[0] + 1e-9);
    ll ansh = ans / 3600, ansm = (ans % 3600) / 60, anss = ans % 60;
    if(ansh < 10) cout << '0';
    cout << ansh;
    cout << ':';
    if(ansm < 10) cout << '0';
    cout << ansm;
    cout << ':';
    if(anss < 10) cout << '0';
    cout << anss;
    cout << '\n';
}

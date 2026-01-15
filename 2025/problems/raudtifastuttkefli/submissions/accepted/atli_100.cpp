#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;

ll memo[1000][100001];
int n, k;
int L[1000], D[1000];

// looking at video i
// have s time left
ll dp(int i, int s) {
    if(i >= n) return 0;
    if(memo[i][s] != -1)
        return memo[i][s];
    memo[i][s] = 0;
    if(s >= k)
        memo[i][s] = max(memo[i][s], dp(i + 1, s - k));
    if(s >= L[i])
        memo[i][s] = max(memo[i][s], dp(i + 1, s - L[i]) + D[i]);
    return memo[i][s];
}

int main() {
    memset(memo, -1, sizeof(memo));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    ll S = 0, R = 0;
    for(int i = 0; i < n; ++i) {
        cin >> L[i] >> D[i];
        S += L[i];
        R += D[i];
    }
    int T; cin >> T;
    if(T >= S) {
        cout << R << '\n';
        return 0;
    }
    cout << dp(0, T) << '\n';
}

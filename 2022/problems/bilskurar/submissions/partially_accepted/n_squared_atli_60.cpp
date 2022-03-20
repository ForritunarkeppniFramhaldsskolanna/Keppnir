#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    for(int i = 0; i < n; ++i) cin >> a[i], a[i]--;
    for(int i = 0; i < n; ++i) cin >> b[i], b[i]--;
    for(int i = 0; i < n; ++i) c[a[i]] = i, d[b[i]] = i;
    long long ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j) 
            if((c[i] < c[j]) != (d[i] < d[j]))
                ans++;
    cout << ans << '\n';
}

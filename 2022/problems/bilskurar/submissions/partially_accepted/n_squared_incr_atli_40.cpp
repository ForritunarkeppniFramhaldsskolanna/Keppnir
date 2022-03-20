#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    long long ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j) 
            if(b[i] > b[j])
                ans++;
    cout << ans << '\n';
}

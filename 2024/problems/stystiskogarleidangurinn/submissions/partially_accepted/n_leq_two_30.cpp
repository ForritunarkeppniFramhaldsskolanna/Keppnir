#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    if(n == 1) {
        int health;
        cin >> health;

        if (s) cout << 0 << endl;
        else cout << health << endl;
    } else {
        int health1, health2;
        cin >> health1 >> health2;

        int ans = 0;
        int u, v, t;
        cin >> u >> v >> t;

        ans += t;
        if (s == 0) ans += health1 + health2;
        if (s == 1) ans += min(health1, health2);
        cout << ans << endl;
    }
}

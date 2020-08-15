#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    vi t(n);
    for(int i=0;i<n;i++){
        cin >> t[i];
    }

    ll top_sum = 0;
    ll bottom_sum = 0;
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        top_sum += abs(t[i] - t[j]);
        bottom_sum += 2 * t[i];
    }
    }

    cout << fixed << setprecision(17) << (double)top_sum / (double)bottom_sum << endl;

    return 0;
}


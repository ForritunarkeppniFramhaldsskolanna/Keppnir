#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int d = 2 * n + 3;
    vector<string> box(d, string(d, ' '));
    box[0][n + 1] = box.back()[n + 1] = 'x';
    box[n + 1][0] = box[n + 1].back() = 'x';
    for(int i = 1; i <= n; ++i) {
        box[i][n + 1 - i] = '/';
        box[i][n + 1 + i] = '\\';
        box[i + n + 1][i] = '\\';
        box[n + 1 + i][d - i - 1] = '/';
    }
    for(int i = 0; i < d; ++i) {
        cout << box[i] << '\n';
    }
}

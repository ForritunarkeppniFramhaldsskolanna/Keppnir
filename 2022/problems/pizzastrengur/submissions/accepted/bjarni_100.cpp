#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int res = -1;
    vector<char> cs = {'P', 'I', 'Z', 'A'};
    string ans = "";
    while (res != 2 && ans.size() != n) {
        random_shuffle(cs.begin(), cs.end());
        for (int i = 0; i < cs.size(); i++) {
            if (i == cs.size() - 1) {
                ans += cs[i];
                break;
            }
            cout << ans + cs[i] << endl;
            cin >> res;
            if (res != 0) {
                ans += cs[i];
                break;
            }
        }
    }
    if (res != 2) {
        cout << ans << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, x, mult = 1, seq = 0, score = 0;
    cin >> n;
    while(n--) {
        cin >> x;
        if(x == 0) {
            if(mult > 1) mult /= 2;
            seq = 0;
        } else {
            seq++;
            if(seq == 2 * mult && mult < 8) {
                mult *= 2;
                seq = 0;
            }
            score += x * mult;
        }
    }
    cout << score << '\n';
}

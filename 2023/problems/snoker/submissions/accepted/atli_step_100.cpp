#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-9;

int main() {
    ios_base::sync_with_stdio(false);
    int n; double sx, sy, vx, vy; cin >> n;
    vector<string> colour(n);
    vector<double> xs(n), ys(n);
    for(int i = 0; i < n; ++i) {
        cin >> colour[i] >> xs[i] >> ys[i];
        if(colour[i] == "white") sx = xs[i], sy = ys[i];
    }
    string targ;
    cin >> targ >> vx >> vy;
    for(int stp = 0; stp < 1000005; stp++) {
        sx += vx * 1e-6;
        sy += vy * 1e-6;
        if(sx < 1 - eps) vx = -vx, sx = 2 - sx;
        if(sx > 69 + eps) vx = -vx, sx = 138 - sx;
        if(sy < 1 - eps) vy = -vy, sy = 2 - sy;
        if(sy > 139.5 + eps) vy = -vy, sy = 279 - sy;
        for(int i = 0; i < n; ++i) {
            if(colour[i] == "white") continue;
            if((xs[i] - sx) * (xs[i] - sx) + (ys[i] - sy) * (ys[i] - sy) < 4) {
                if(colour[i] == targ) cout << "HIT\n";
                else cout << "FOUL\n";
                return 0;
            }
        }
    }
    cout << "MISS\n";
}

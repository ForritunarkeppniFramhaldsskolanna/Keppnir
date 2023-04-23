#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,ii> i4;

void finish(int i) {
    cout << i << '\n';
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    int q, n, m, x1, y1, x2, y2;
    cin >> q >> n >> m;
    set<i4> cuts;
    for(int i = 1; i <= q; ++i) {
        cin >> y1 >> x1 >> y2 >> x2;
        if(x1 > x2) swap(x1, x2), swap(y1, y2);
        if(y1 == y2) {
            if(cuts.count(i4(ii(x1, 1 - y1), ii(x2, 1 - y2)))) finish(i);
            if(cuts.count(i4(ii(x1, y1), ii(x1, 1 - y1))) &&
                cuts.count(i4(ii(x1, 1 - y1), ii(x1 - 1, 1 - y1)))) finish(i);
            if(cuts.count(i4(ii(x2, y2), ii(x2, 1 - y2))) &&
                cuts.count(i4(ii(x2, 1 - y2), ii(x2 + 1, 1 - y2)))) finish(i);
        } else {
            if(cuts.count(i4(ii(x1, y1), ii(x1 - 1, y1))) &&
                cuts.count(i4(ii(x2, y2), ii(x2 + 1, y2)))) finish(i);
            if(cuts.count(i4(ii(x1, y1), ii(x1 + 1, y1))) &&
                cuts.count(i4(ii(x2, y2), ii(x2 - 1, y2)))) finish(i);
        }
        cuts.insert(i4(ii(x1, y1), ii(x2, y2)));
        cuts.insert(i4(ii(x2, y2), ii(x1, y1)));
        if(cuts.count(i4(ii(0, 0), ii(0, 1))) && cuts.count(i4(ii(0, 0), ii(1, 0)))) finish(i);
        if(cuts.count(i4(ii(m, 1), ii(m, 0))) && cuts.count(i4(ii(m, 1), ii(m - 1, 1)))) finish(i);
    }
    cout << "-1\n";
}

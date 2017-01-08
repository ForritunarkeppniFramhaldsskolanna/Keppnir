#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
template <class T> int size(const T &x) { return x.size(); }
const int INF = 2147483647;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int main() {
    int n, m;
    scanf("%d", &n);
    m = n;
    vector<ii> ev;
    rep(i,0,n) {
        int a, b;
        scanf("%d %d", &a, &b);
        ev.push_back(ii(a,-b));
    }
    rep(i,0,m) {
        int sz;
        scanf("%d", &sz);
        ev.push_back(ii(sz, 1));
    }

    sort(ev.begin(), ev.end());
    priority_queue<int,vector<int>,greater<int> > pq;
    rep(i,0,size(ev)) {
        if (ev[i].second == 1) {
            if (!pq.empty()) {
                if (pq.top() < ev[i].first) {
                    printf("Neibb\n");
                    return 0;
                }
                pq.pop();
            }
        } else {
            pq.push(-ev[i].second);
        }
    }
    if (!pq.empty()) {
        printf("Neibb\n");
        return 0;
    }

    printf("Jebb\n");

    return 0;
}


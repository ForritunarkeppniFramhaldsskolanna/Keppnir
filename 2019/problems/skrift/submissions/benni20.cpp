#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;

int main() {
    cin.sync_with_stdio(false);
    int n,m,q;
    cin >> n >> m >> q;
    vii M(m);
    rep(i,0,m) cin >> M[i].fs >> M[i].sc;
    int cost = M[0].sc;
    int sm = 0;
    if(m == 1) {
        rep(i,0,q) {
            int a,b;
            cin >> a >> b;
            if(a == 2) sm += b*cost;
        }
        cout << sm << endl;
    } else {
        vii Q(q);
        rep(i,0,q) cin >> Q[i].fs >> Q[i].sc;

        int ac = M[0].fs, bc = M[1].fs;
        int am = M[0].sc, bm = M[1].sc;

        int mx = 0;
        for(int i = 0; i < (1<<n); i++) {
            int firstcnt = 0;
            int secondcnt = 0;
            string s = "";
            for(int j = 0; j < n; j++) {
                if(i & (1<<j)) {
                    firstcnt += 1;
                    s += "1";
                } else {
                    secondcnt += 1;
                    s += "0";
                }
            }
            if(firstcnt == ac && secondcnt == bc) {
                int at = 0;
                int sm = 0;
                int nmtimes = 0;
                rep(z,0,q) {
                    if(Q[z].fs == 1) at += Q[z].sc;
                    else {
                        for(int j = at-1; j >= at-Q[z].sc; j--) {
                        if((1 << j) & i) {
                                sm += am;
                            } else {
                                sm += bm;
                            }
                        }
                        at -= Q[z].sc;
                    }
                }
                mx = max(mx,sm);
            }
        }
        cout << mx << endl;

    }
    return 0;
}



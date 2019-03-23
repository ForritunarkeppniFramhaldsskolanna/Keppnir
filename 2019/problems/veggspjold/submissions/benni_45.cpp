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

int val[2001][2001];

int main() {
    cin.sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    swap(n,m);
    memset(val,0,sizeof(val));
    rep(i,0,k) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        rep(y,c,d) {
            rep(x,a,b) {
                val[y][x] = 1;
            }
        }
    }
    int cnt = 0;
    rep(i,0,n) rep(j,0,m) if(val[i][j] == 0) cnt += 1;
    cout << cnt << endl;
    return 0;
}



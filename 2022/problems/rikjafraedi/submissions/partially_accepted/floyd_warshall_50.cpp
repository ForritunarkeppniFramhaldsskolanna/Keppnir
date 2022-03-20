#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(auto i = (a); i < (b); ++i)
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
const ll INF = ~(1LL<<63);

void floyd_warshall(vvi &arr) {
  int n = arr.size();
  rep(k,0,n) rep(i,0,n) rep(j,0,n)
    if (arr[i][k] != INF && arr[k][j] != INF)
      arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
  // Check negative cycles
  rep(i,0,n) rep(j,0,n) rep(k,0,n)
    if (arr[i][k] != INF && arr[k][k] < 0 && arr[k][j]!=INF)
      arr[i][j] = -INF; }

int main() {
    ll n, a, x, y, p[3];
    cin >> n >> a;
    vvi g[3];
    rep(i,0,3) g[i] = vvi(n, vi(n, INF));
    rep(i,0,a) {
        cin >> x >> y >> p[0] >> p[1] >> p[2];
        x--; y--;
        rep(j,0,3) {
            if(g[j][x][y] != INF && g[j][x][y] != p[j]) {
                cout << "Neibb\n";
                return 0;
            }
            g[j][x][y] = p[j];
            g[j][y][x] = -p[j];
        }
    }
    rep(i,0,3) floyd_warshall(g[i]);
    rep(i,0,3) rep(j,0,n) {
        if(g[i][j][j] == -INF) {
            cout << "Neibb\n";
            return 0;
        }
    }
    cout << "Jebb\n";
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const int INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;
typedef unsigned long long ull;

template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

char C[3][200'050];
int dx[6] = {1,1,0,0,-1,-1};
int dy[6] = {1,-1,1,-1,1,-1};

int main() {
    cin.sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    rep(i,0,2) rep(j,0,n) cin >> C[i][j];
    int blocks = 0;
    rep(i,0,2) rep(j,0,n) {
        ii at = ii(i,j);
        if(C[at.fs][at.sc] != 'o') continue;
        rep(z,0,3) {
            ii nx = ii(at.fs+ dy[z], at.sc+dx[z]);
            if(0 <= nx.fs && nx.fs < 2 && 0 <= nx.sc && nx.sc < n) {
                if(C[nx.fs][nx.sc] == 'o') blocks++;
            }
        }
    }
    rep(i,0,q) {
        char c;
        cin >> c;
        if(c == 'Q') {
            if(blocks == 0) cout << "Jebb" << endl;
            else cout << "Neibb" << endl;
        } else {
            int x,y;
            cin >> x >> y;
            x--;y--;
            int add = 1;
            if(C[x][y] == 'o') add = -1;

            ii at = ii(x,y);
            rep(z,0,6) {
                ii nx = ii(at.fs+ dy[z], at.sc+dx[z]);
                if(0 <= nx.fs && nx.fs < 2 && 0 <= nx.sc && nx.sc < n) {
                    if(C[nx.fs][nx.sc] == 'o') blocks += 1 * add;
                }
            }
            if(C[x][y] == 'o') C[x][y]= '.';
            else C[x][y]  = 'o';
        }
    }
    return 0;
}














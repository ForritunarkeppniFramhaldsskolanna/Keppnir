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

int memo[1200][1200];
int memo2[1200][1200];
int A[1200][1200];
int O[1200][1200];
int n,k;

int dp(int i, int j) {
    if(i < 0 || j < 0) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    if(i == 0 && j == 0) return memo[i][j] = A[i][j];
    if(i == 0) return memo[i][j] = A[i][j] + dp(i,j-1);
    if(j == 0) return memo[i][j] = A[i][j] + dp(i-1,j);
    return memo[i][j] = A[i][j] + dp(i-1,j) + dp(i,j-1) - dp(i-1,j-1);
}

int dp2(int i, int j) {
    if(i < 0 || j < 0) return 0;
    if(memo2[i][j] != -1) return memo2[i][j];
    if(i == 0 && j == 0) return memo2[i][j] = O[i][j];
    if(i == 0) return memo2[i][j] = O[i][j] + dp2(i,j-1);
    if(j == 0) return memo2[i][j] = O[i][j] + dp2(i-1,j);
    return memo2[i][j] = O[i][j] + dp2(i-1,j) + dp2(i,j-1) - dp2(i-1,j-1);
}

int calc_box(int x_l, int x_r, int y_bot, int y_top) {
    x_l--;
    y_bot--;
    return dp(x_r, y_top) - dp(x_l, y_top) - dp(x_r, y_bot) + dp(x_l, y_bot);  
}

int calc_box2(int x_l, int x_r, int y_bot, int y_top) {
    x_l--;
    y_bot--;
    return dp2(x_r, y_top) - dp2(x_l, y_top) - dp2(x_r, y_bot) + dp2(x_l, y_bot);  
}

int main() {
    cin.sync_with_stdio(false);
    memset(memo,-1,sizeof(memo));
    memset(memo2,-1,sizeof(memo));
    memset(A,0,sizeof(A));
    memset(O,0,sizeof(O));
    cin >> n >> k;
    if(n > 400 | k > 400) return 0;
    rep(i,0,n) rep(j,0,n) {
        char c;
        cin >> c;
        if(c != '.') {
            O[i][j] = 1;
            if(c != '#') {
                A[i][j] = c-'0';
            }
        }
    }
    int mx = 0;
    for(int i = 0; i < n - k + 1; i++) {
        for(int j = 0; j < n - k + 1; j++) {
            int b1_o = calc_box2(i,i+k-1, j, j+k-1);
            int b2_o = calc_box2(i+1,i+k-2, j+1,j+k-2);
            if(b1_o == b2_o)  {
                mx = max(mx, calc_box(i,i+k-1,j,j+k-1));
            }
        }
    }
    cout << mx << endl;
    return 0;
}























































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

int A[1200][1200];
int O[1200][1200];
int n,k;



int main() {
    cin.sync_with_stdio(false);
    memset(A,0,sizeof(A));
    memset(O,0,sizeof(O));
    cin >> n >> k;
    //if(n > 400 || k > 400) return 0;
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
            int b1_o = 0;
            int b2_o = 0;
            int val = 0;
            for(int x = i; x < i+k; x++) {
                for(int y = j; y < j+k; y++) {
                    b1_o += O[x][y];
                }
            }
            for(int x = i+1; x < i+k-1; x++) {
                for(int y = j+1; y < j+k-1; y++) {
                    b2_o += O[x][y];
                }
            }
            for(int x = i; x < i+k; x++) {
                for(int y = j; y < j+k; y++) {
                    val += A[x][y];
                }
            }
            if(b1_o == b2_o) {
                mx = max(mx,val);
            }

        }
    }
    cout << mx << endl;
    return 0;
}























































#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int A[60][60];

int main() {
    cin.sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    rep(i,0,n) rep(j,0,m)  cin >> A[i][j];
    rep(i,1,2) rep(j,1,m-1) {
        int cnt = 0;
        rep(z,0,4) {
            if(A[i+dx[z]][j+dy[z]] > A[i][j]) cnt++;
        }
        if(cnt == 4) {
            cout << "Jebb" << endl;
            return 0;
        }
    }
    cout << "Neibb" << endl;
    return 0;
}



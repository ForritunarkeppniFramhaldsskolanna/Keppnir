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

int main() {
    cin.sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int bst = -1;
    vi P(n+10,0);
    rep(i,0,n) {
        if(s[i] == '#') P[i+1] += 1;
        P[i+1] += P[i];
    }
    for(int i = 1; i < n-1; i++) {
        if(i+m >= n) continue;
        if(s[i+m] != '#') continue;
        if(s[i-1] != '#') continue;
        int cost = P[i+m]-P[i];
        if(bst == -1) {
            bst = cost;
        } else bst = min(bst, cost);
    }
    if(bst == -1) {
        cout << "Neibb" << endl;
        return 0;
    }
    cout << bst << endl;
    return 0;
}



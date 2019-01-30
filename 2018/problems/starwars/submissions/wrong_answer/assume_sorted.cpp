#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31); // 2147483647

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) { return (a % b + b) % b; }

int main(){
    int n;
    cin >> n;
    vi v(n);
    rep(i,0,n) cin >> v[i];
    rep(i,n/3, 2*n/3) cout << v[i] << " ";
    rep(i,0,n/3) cout << v[i] << " ";
    rep(i,2*n/3,n) cout << v[i] << " ";
    cout << endl;
    return 0;
}

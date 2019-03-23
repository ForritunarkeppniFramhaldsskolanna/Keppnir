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

vi v;
int n;
int mem[2510][2510];

int dp(int at, int lst){
    if(at == n) return 0;
    if(mem[at][lst] != -1) return mem[at][lst];
    int ans = dp(at+1, lst);
    if(lst == n || v[at] < v[lst]) ans = max(ans, 1+dp(at+1, at));
    return mem[at][lst] = ans;
}

int main(){
    cin.sync_with_stdio(false);
    cin >> n;
    memset(mem, -1, sizeof(mem));
    int x;
    rep(i,0,n) {
        cin >> x;
        v.push_back(x);
    } 
    cout << dp(0, n) << endl;
    return 0;
}

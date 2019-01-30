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
    int n, L;
    cin >> n >> L;
    int mx = 0, mxi = -1;
    rep(i,0,n){
        int a,b;
        cin >> a >> b;
        if(b > mx) {
            mx = b;
            mxi = i;
        }
    }
    cout << "1 " << mx << endl;
    cout << mxi << endl;
    return 0;
}

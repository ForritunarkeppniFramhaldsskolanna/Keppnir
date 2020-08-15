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

int main() {
    cin.sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    if(n > 20 || k > 20) return 0;
    vi A(n);
    rep(i,0,n) cin >> A[i];
    rep(i,0,n) if(A[i] != 1) return 0;
    cout << (n/k)*(2) << endl;
    return 0;
}



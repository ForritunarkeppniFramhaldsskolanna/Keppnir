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
    ll n,m,k;
    cin >> n >> m >> k;
    if(m > k) {
        cout << ":(" << endl;
    } else {
        ll sm = 0;
        ll number_per_day = k/m;
        rep(i,0,n) {
            ll a;
            cin >> a;
            sm += a;
        }
        cout << ((sm+number_per_day-1)/number_per_day) << endl;
    }
    return 0;
}



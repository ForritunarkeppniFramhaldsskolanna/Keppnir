#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T> ll size(const T &x) { return x.size(); }
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const ll INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;


char R[120][120];

int main() {
    cin.sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vii A;
    char c;
    rep(i,0,n) {
        rep(j,0,m) {
            cin  >> c;
            if(c == '*') {
                A.pb(ii(i+1,j+1));
            }
        }
    }
    sort(A.begin(), A.end());
    cout << A.size() << endl;
    rep(i,0,A.size()) cout << A[i].fs << " " << A[i].sc << endl;
    return 0;
}



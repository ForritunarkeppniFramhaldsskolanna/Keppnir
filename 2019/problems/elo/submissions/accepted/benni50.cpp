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

int n;
int L[1050];
int R[1050];
int A[1050];

int main() {
    cin.sync_with_stdio(false);
    int x;
    cin >> n >> x;
    rep(i,0,n) cin >> L[i] >> R[i] >> A[i];

    while(true) {
        bool found = false;
        rep(i,0,n) {
            if(L[i] <= x && x <= R[i]) {
                found = true;
                x += A[i];
            }
        }
        if(!found) break;
    }
    cout << x << endl;
    return 0;
}



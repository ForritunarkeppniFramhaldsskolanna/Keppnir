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

int main() {
    cin.sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    bool arnar_wins = false;
    int h = n/3;
    int extra = n%3;
    int i = h;
    int j = h;
    int k = h;
    if(extra == 2) {
        i++;
        j++;
    } else {
        i++;
    }
    vi T = {i+1,j+1,k+1};
    sort(T.begin(), T.end());
    if(T[0] + T[1] > m) arnar_wins = true;

    if(arnar_wins) cout << "Arnar" << endl;
    else cout << "Unnar" << endl;
}



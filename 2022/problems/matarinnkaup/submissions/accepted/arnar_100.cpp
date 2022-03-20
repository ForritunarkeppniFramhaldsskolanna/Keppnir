#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
#define fs first
#define sc second
#define pb push_back
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

int main()
{
    ios_base::sync_with_stdio(false);

    int u, k;
    cin >> u >> k;

    map<string, map<string, ll> > recipes;
    map<string, ll> occ;
    map<string, ll> ingr_occ;
    rep(i,0,u) {
        string name;
        cin >> name;
        int h;
        cin >> h;
        rep(j,0,h) {
            string ing;
            ll cnt;
            cin >> ing >> cnt;
            // Should be able to assign instead of add
            recipes[name][ing] = cnt;
        }
    }

    rep(i,0,k) {
        int n;
        cin >> n;
        rep(j,0,n) {
            string dish;
            ll cnt;
            cin >> dish >> cnt;
            occ[dish] += cnt;
        }
    }

    iter(dish, occ) {
        iter(ingr, recipes[dish->first]) {
            ingr_occ[ingr->first] += dish->second * ingr->second;
        }
    }

    iter(it, ingr_occ) {
        if (it->second > 0) {
            cout << it->first << " " << it->second << "\n";
        }
    }
    cout.flush();

    return 0;
}

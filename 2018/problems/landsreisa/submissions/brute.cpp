#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<double, double> dd;

const ll INF = (1LL<<60);
const double pi = acos(-1);
const double EPS = 1e-9;

#define MAXN 1000

dd points[MAXN];

double dist(dd a, dd b)
{
    double difx = a.first - b.first, dify = a.second - b.second;
    return sqrt(difx*difx + dify*dify);
}

pair<vi,double> brute(int n)
{
    vi cur(n), best;
    rep(i,0,n) cur[i] = i;
    double mn = INFINITY;
    do
    {
        double curdist = 0;
        rep(i,0,n)
        {
            curdist += dist(points[cur[i]], points[cur[(i+1)%n]]);
        }
        if(curdist < mn)
        {
            mn = curdist;
            best = cur;
        }
    } while(next_permutation(cur.begin()+1, cur.end()));
    return make_pair(best, mn);
}

int main()
{
    int n;
    cin >> n;
    rep(i,0,n)
    {
        cin >> points[i].first >> points[i].second;
    }
    pair<vi,double> res = brute(n);
    vi path = res.first;
    double opt = res.second;
    rep(i,0,n)
    {
        cout << path[i] << " ";
    }
    cout << endl << "Length: " << opt << endl;
}

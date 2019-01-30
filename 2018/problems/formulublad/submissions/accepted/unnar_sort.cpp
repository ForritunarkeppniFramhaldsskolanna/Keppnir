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
    vector<pair<ii, int> > v(n);
    rep(i,0,n){
        ii p;
        cin >> p.first >> p.second;
        p.second = -p.second;
        v[i] = make_pair(p, i);
    }
    sort(v.begin(), v.end());
    int sm = 0;
    vi ans;
    int left = L;
    rep(i,0,n){
        if(left < v[i].first.first) break;
        sm -= v[i].first.second;
        left -= v[i].first.first;
        ans.push_back(v[i].second);
    }
    cout << size(ans) << " " << sm << endl;
    rep(i,0,size(ans)){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
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
    int n, m;
    cin >> n >> m;
    if(n > 500) return 0;
    vector<string> names(n);
    map<string, vector<string> > adj;
    map<string, vector<string> > radj;
    rep(i,0,n)
    {
        cin >> names[i];
        radj[names[i]] = vector<string>();
    }
    rep(i,0,m)
    {
        string a, b, c;
        cin >> a >> b >> c;
        if(b == ">") swap(a,c);
        adj[a].push_back(c);
        radj[c].push_back(a);
    }

    queue<string> roots;
    iter(it, radj)
    {
        if(size(it->second) == 0)
        {
            roots.push(it->first);
        }
    }
    vector<string> res;
    while(!roots.empty())
    {
        if(size(roots) > 1)
        {
            cout << "veit ekki" << endl;
            return 0;
        }
        string s = roots.front();
        roots.pop();
        res.push_back(s);
        iter(it, adj[s])
        {
            radj[*it].erase(find(radj[*it].begin(), radj[*it].end(), s));
        }
        iter(it, radj)
        {
            if(size(it->second) == 0 && find(res.begin(), res.end(), it->first) == res.end()) roots.push(it->first);
        }
    }
    
    if(size(res) == n)
    {
        rep(i,0,n)
        {
            cout << (i ? " " : "") << res[i];
        }
        cout << endl;
    }
    else
    {
        // SHOULD NOT HAPPEN
        cout << "WAT???" << endl;
        rep(i,0,size(res))
        {
            cout << (i ? " " : "") << res[i] << endl;
        }
        cout << endl;
        assert(false);
    }
    return 0;
}

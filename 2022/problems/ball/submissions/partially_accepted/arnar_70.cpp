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

    int n;
    cin >> n;
    vii pairs(n/2+1);
    rep(i, 0u, pairs.size())
    {
        cin >> pairs[i].first >> pairs[i].second;
    }

    rep(i, 0u, pairs.size())
    {
        bool conflict = false;
        vector<bool> s(n+1, false);
        rep(j, 0u, pairs.size())
        {
            if (i == j) continue;
            if(s[pairs[j].first] || s[pairs[j].second])
            {
                conflict = true;
            }
            s[pairs[j].first] = true;
            s[pairs[j].second] = true;
        }
        if(!conflict)
        {

            cout << min(pairs[i].first, pairs[i].second) << " " 
                 << max(pairs[i].first, pairs[i].second) << endl;
            break;
        }
    }

    return 0;
}

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

    map<char, int> COST{{ { '.', 20 },
                         { 'O', 10 },
                         { '\\', 25 },
                         { '/', 25 },
                         { 'A', 35 },
                         { '^', 5  },
                         { 'v', 22 }
    }};
    int n, m;
    int result = 0;
    cin >> n >> m;
    string s;
    rep(i, 0, n)
    {
        cin >> s;
        rep(j, 0, m)
        {
            result += COST[s[j]];
        }
    }
    cout << result << endl;

    return 0;
}

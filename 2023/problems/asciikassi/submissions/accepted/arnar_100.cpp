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

    for(int i = 0; i < n+2; i++)
    {
        bool hline = i == 0 || i == n+1;
        for(int j = 0; j < n+2; j++)
        {
            bool vline = j == 0 || j == n+1;
            if (hline && vline) cout << '+';
            else if (hline) cout << '-';
            else if (vline) cout << '|';
            else cout << ' ';
        }
        cout << endl;
    }
}

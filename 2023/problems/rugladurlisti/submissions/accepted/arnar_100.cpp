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
    
    vector<int> indices(n);

    for(int mask = 1; mask <= n; mask <<= 1)
    {
        vector<int> query;
        for(int i = 0; i < n; i++)
        {
            if ((i & mask) == mask)
            {
                query.push_back(i+1);
            }
        }
        cout << "? " << query.size();
        for(auto x : query)
        {
            cout << " " << x;
        }
        cout << endl;

        for(size_t i = 0; i < query.size(); i++)
        {
            int x;
            cin >> x;
            indices[x-1] += mask;
        }
    }

    vector<int> answer(n);
    for(int i = 0; i < n; i++)
    {
        answer[indices[i]] = i;
    }

    cout << "!";
    for(auto x : answer)
    {
        cout << " " << x+1;
    }
    cout << endl;

    return 0;
}

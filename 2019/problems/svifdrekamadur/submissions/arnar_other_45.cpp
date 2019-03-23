#include <bits/stdc++.h>
#pragma GCC target("arch=sandybridge")
#pragma GCC optimize("O3")
#pragma GCC optimize("expensive-optimizations")
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
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

int arr[100010];

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    map<int, vi, greater<int>> m; // store the indices where each value apppears in decreasing order
    rep(i,0,n) cin >> arr[i], m[arr[i]].push_back(i);
    vector<int> s;
    int mx = 0;
    iter(it, m) // iterate through all distinct values
    {
        // add the indices of the current value to the set
        iter(ot, it->second) s.push_back(*ot);
        
        // for each index with this value
        iter(ot, it->second)
        {
            // The building we are currently looking at is the one where we will land
            // We need to check for the first building to the left
            // and to the right of the current building, in the set s.
            // There are three cases
            // - If there is not building we do nothing
            // - If the building is of equal height we ignore it because the starting building must be strictly taller
            // - If the building is taller then it is a possible answer, update the maximum
            // Use binary search to do this in O(log n) time for a runtime of O(n log n)
            int lv = -1, rv = n;
            iter(ut, s)
            {
                if(*ut < *ot) lv = max(*ut, lv);
                if(*ut > *ot) rv = min(*ut, rv);
            }
            if(lv > -1 && arr[lv] > it->first)
            {
                mx = max(mx, *ot - lv);
            }

            if(rv < n && arr[rv] > it->first)
            {
                mx = max(mx, rv - *ot);
            }
        }
    }

    cout << mx << endl;

    return 0;
}

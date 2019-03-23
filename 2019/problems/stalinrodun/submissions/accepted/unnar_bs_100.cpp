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
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    vi v;
    rep(i,0,n){
        int x;
        cin >> x;
        int lo = 0, hi = size(v)-1;
        int ans = -1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(v[mid] <= x){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        if(ans == -1) v.push_back(x);
        else v[ans] = x;
    }
    cout << size(v) << endl;
    return 0;
}

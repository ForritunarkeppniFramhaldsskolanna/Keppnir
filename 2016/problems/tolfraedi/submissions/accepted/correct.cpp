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
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T mod(T a, T b) { return (a % b + b) % b; }

multiset<int> S;

int main(){
    int Q;
    ll sum = 0;
    cin >> Q;
    string op;
    int val;
    rep(i,0,Q){
        cin >> op >> val;
        if(op == "A"){
            sum += val;
            S.insert(val);
        } else {
            sum -= val;
            S.erase(S.find(val));
        }
        if(size(S))
            printf("%d %d %.6Lf\n", *S.begin(), *S.rbegin(), (1.0L*sum) / size(S));
        else {
            printf("-1 -1 -1\n");
        }
    }
}

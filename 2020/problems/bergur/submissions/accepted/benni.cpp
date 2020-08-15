#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const int INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;
typedef unsigned long long ull;

template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

int main() {
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    vi A(n);
    rep(i,0,n) cin >> A[i];
    ll total_sum = 0;
    multiset<int> K;
    rep(i,0,n) K.insert(A[i]);
    int val = 0;
    rep(i,0,n) {
        auto it = K.begin();
        val = max(val, *it);
        total_sum += val;
        K.erase(K.find(A[i]));
    }
    cout << total_sum << endl;
    return 0;
}



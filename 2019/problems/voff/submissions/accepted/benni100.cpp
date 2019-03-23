#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T> ll size(const T &x) { return x.size(); }
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const ll INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;

int main() {
    cin.sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vi A(n);
    rep(i,0,n) cin >> A[i];
    sort(A.begin(), A.end());
    int dogs = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    rep(i,0,n) {
        while(true) {
            if(pq.empty()) break;
            int at = pq.top();
            if(A[i]-at >= k) {
                pq.pop();
                dogs += 1;
            } else break;
        }
        if(dogs > 0) {
            dogs--;
            pq.push(A[i]);
        } else {
            pq.push(A[i]);
        }
    }
    dogs += pq.size();
    cout << dogs << endl;
    return 0;
}



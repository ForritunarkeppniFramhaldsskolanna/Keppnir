#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;

int main() {
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    int bst = 0;
    vi A(n);
    rep(i,0,n) cin >> A[i];
    int mx = 0;
    rep(i,0,n) mx = max(mx, A[i]);
    if(n <= 5000) {
        rep(i,0,n) {
            int a_i = A[i];
            int othmx = 0;
            rep(j,i+1,n) {
                int a_j = A[j];
                if(a_i > a_j || a_j > a_i) {
                    if(othmx < min(a_j,a_i)) {
                        bst = max(j-i,bst);
                    }
                }
                othmx = max(othmx, a_j);
            }
        }
    } else if(mx <= 100){
        vector<int> K[120];
        rep(i,0,n) K[A[i]].pb(i);
        rep(i,0,n) {
            int a_i = A[i];
            vii Ans;
            rep(j,0,102) {
                if(K[j].size() == 0) {
                    continue;
                }
                int lo = 0, hi = int(K[j].size())-1;
                int good = -1;
                while(lo <= hi) {
                    int mid = (lo+hi)/2;
                    if(K[j][mid] > i) {
                        hi = mid-1;
                        good = K[j][mid];
                    } else {
                        lo = mid+1;
                    }
                }
                if(good != -1) {
                    Ans.pb(ii(good,j));
                }
            }
            sort(Ans.begin(), Ans.end());
            int othmx = 0;
            rep(j,0,Ans.size()) {
                int a_j = Ans[j].sc;
                if(a_i > a_j || a_j > a_i) {
                    if(othmx < min(a_i,a_j)) {
                        bst = max(Ans[j].fs-i, bst);
                    }
                }
                othmx = max(othmx, a_j);
            }
        }
    }
    cout << bst << endl;
    return 0;
}



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
    int n,m;
    cin >> n >> m;
    vi A(n);
    rep(i,0,n) cin >> A[i];
    rep(i,0,n) {
        if(A[i] == m) {
            if(i == 1) cout << "naest";
            else if(i > 1) cout << i+1 << " ";
            cout << "fyrst" << endl;
        }
    }
    return 0;
}



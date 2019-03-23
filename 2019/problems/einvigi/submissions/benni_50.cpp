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

int awin = 0;
int bwin = 0;

void inc(int a, int b) {
    if(a > b) awin++;
    if(a < b) bwin++;
}

void dec(int a, int b) {
    if(a > b) awin--;
    if(a < b) bwin--;
}

int main() {
    cin.sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    vi A(n), B(n);
    rep(i,0,n) cin >> A[i];
    rep(i,0,n) cin >> B[i];
    rep(i,0,n) {
        inc(A[i], B[i]);
    }
    rep(i,0,n) {
        rep(j,i,min(i+m,n)) {
            dec(A[j],B[j]);
            inc(A[j]+k,B[j]);
        }
        if(awin > bwin) {
            cout << i << endl;
            return 0;
        }
        rep(j,i,min(i+m,n)) {
            dec(A[j]+k,B[j]);
            inc(A[j],B[j]);
        }
    }
    cout << "Neibb" << endl;

    return 0;
}



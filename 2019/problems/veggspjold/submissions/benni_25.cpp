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

struct box {
    int x1,x2,y1,y2;
    box(int _x1, int _x2, int _y1, int _y2) {
        x1 = _x1;
        x2 = _x2;
        y1 = _y1;
        y2 = _y2;
    }

    int L() {
        return y2-y1;
    }
    int B() {
        return x2-x1;
    }

    int size() {
        return L()*B();
    }
};

int COL(box A, box B) {
    if(A.y1 > B.y2) return 0;
    if(A.y2 < B.y1) return 0;
    if(A.x2 < B.x1) return 0;
    if(A.x1 > B.x2) return 0;
    int x1 = max(A.x1, B.x1);
    int x2 = min(A.x2, B.x2);
    int y1 = max(A.y1, B.y1);
    int y2 = min(A.y2, B.y2);
    box c = box(x1,x2,y1,y2);
    return c.size();
}

int main() {
    cin.sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    int total = n*m;
    vector<box> A;
    rep(i,0,k) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        A.pb(box(a,b,c,d));
    }
    rep(i,0,k) total -= A[i].size();
    rep(i,0,k) {
        rep(j,i+1,k) {
            total += COL(A[i], A[j]);
        }
    }
    cout << total << endl;
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
template <class T> int size(const T &x) { return x.size(); }
const int INF = 2147483647;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#define SQ(x) ((x)*(x))

struct object {
    ll x, y, z;
    ll r, br;
    object(ll _x, ll _y, ll _z, ll _r, ll _br) {
        x = _x;
        y = _y;
        z = _z;
        r = _r;
        br = _br;
    }
    bool detonates(object other) {
        return SQ(x-other.x) + SQ(y-other.y) + SQ(z-other.z) < SQ(br + other.r);
    }
};

int main() {
    int n;
    cin >> n;
    vector<object> objs;
    rep(i,0,n) {
        ll x, y, z, r;
        cin >> x >> y >> z >> r;
        objs.push_back(object(x,y,z,r, 2*r));
    }
    int m;
    cin >> m;
    vector<bool> visited(n+m);
    stack<int> S;
    rep(i,0,m) {
        ll x, y, z, r;
        cin >> x >> y >> z >> r;
        objs.push_back(object(x,y,z,r,r));
        visited[n+i] = true;
        S.push(n+i);
    }

    while (!S.empty()) {
        int cur = S.top();
        S.pop();
        rep(i,0,n) {
            if (objs[cur].detonates(objs[i]) && !visited[i]) {
                S.push(i);
                visited[i] = true;
            }
        }
    }

    int cnt = 0;
    rep(i,0,n) {
        if (!visited[i]) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}


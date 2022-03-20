#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
#define rep(i,a,b) for(auto i = (a); i < (b); ++i)
#define pb push_back 
#define fs first 
#define sc second 

struct vec3 { 
    ll x, y, z; 
    vec3() : x(0), y(0), z(0) {}
    vec3(ll _x, ll _y, ll _z) : x(_x), y(_y), z(_z) {}
};

vec3 operator+(const vec3 &a, const vec3 &b) { return vec3(a.x + b.x, a.y + b.y, a.z + b.z); }
bool operator!=(const vec3 &a, const vec3 &b) { return a.x != b.x || a.y != b.y || a.z != b.z; }

int main() {
    int n, a, u, v;
    ll x, y, z;
    cin >> n >> a;
    vvii g(n, vii());
    vii uv;
    vector<vec3> e, d(n);
    vi vis(n, 0);
    rep(i,0,a) {
        cin >> u >> v >> x >> y >> z;
        u--; v--;
        g[u].pb(ii(e.size(), v));
        e.pb(vec3(x, y, z));
        uv.pb(ii(u, v));
    }
    rep(i,0,n) {
        if(vis[i]) continue;
        d[i] = vec3();
        vis[i] = 1;
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int c = q.front();
            q.pop();
            for(ii w : g[c]) {
                if(vis[w.sc]) continue;
                q.push(w.sc);
                vis[w.sc] = true;
                d[w.sc] = d[c] + e[w.fs];
            }
        }
    }
    rep(i,0,e.size()) {
        if(d[uv[i].fs] + e[i] != d[uv[i].sc]) {
            cout << "Neibb\n";
            return 0;
        }
    }
    cout << "Jebb\n";
}

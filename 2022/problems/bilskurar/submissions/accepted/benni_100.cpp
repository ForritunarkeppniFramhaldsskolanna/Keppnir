#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(auto i = (a); i < (b); i++)
#define pb push_back
#define fs first
#define sc second
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const double EPS = 1e-9;

struct node {
    ll val;
    node(ll _val) { val = _val; };
};
struct segment_tree {
    ll sz, n;
    vector<node> t;
    segment_tree(ll _n) : sz(_n*4), n(_n) {
        rep(i,0,sz) t.pb(node(0));
    }
    void build(vi &a, ll v=1, ll tl=0, ll tr=-1) {
        if(tr == -1) tr = n-1;
        if(tl == tr) {
            t[v].val = a[tl];
        } else {
            ll tm = (tl+tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = node(t[v*2].val+t[v*2+1].val);
        }
    }
    node query(ll l, ll r, ll v=1, ll tl=0, ll tr=-1) {
        if(tr == -1) tr = n-1;
        if(l > r) return node(0);
        if(l == tl && r == tr) return t[v];
        ll tm = (tl+tr)/2;
        return node( query(l,min(r,tm), v*2, tl, tm).val
                + query(max(l,tm+1), r, v*2+1, tm+1, tr).val);

    }
    void update(ll pos, ll new_val, ll v=1, ll tl=0, ll tr=-1) {
        if(tr == -1) tr = n-1;
        if(tl == tr) t[v].val = new_val;
        else {
            ll tm = (tl+tr)/2;
            if(pos <= tm) update(pos, new_val, v*2, tl, tm);
            else update(pos, new_val, v*2+1, tm+1, tr);
            t[v].val = t[v*2].val + t[v*2+1].val;
        }
    }
};

int main() {
    cin.sync_with_stdio(false);
    ll n;
    cin >> n;
    vi A(n), B(n);
    rep(i,0,n) cin >> A[i];
    rep(i,0,n) cin >> B[i];
    map<ll,ll> PS;
    rep(i,0,n) {
        A[i]--;
        B[i]--;
        PS[B[i]] = i;
    }
    segment_tree sq(n);
    ll sm = 0;
    for(ll i = n-1; i >= 0; i--) {
        if(PS[A[i]] != 0 ) {
            sm += sq.query(0, PS[A[i]] - 1).val;
        }
        sq.update(PS[A[i]], 1);
    }
    cout << sm << endl;
}


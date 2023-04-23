#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

struct fenwick_tree {
    int n; vi bit;
    fenwick_tree(int _n) : n(_n), bit(vi(n)) { }
    void add(int idx, ll val) {
        while(idx < n) bit[idx] += val, idx |= idx + 1;
    }
    ll query(int idx) {
        ll res = 0;
        while(idx >= 0) res += bit[idx], idx = (idx & (idx + 1)) - 1;
        return res;
    }
    ll sum(int l, int r) {
        return query(r) - query(l - 1);
    }
};

const int MXQ = 5e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    int q; cin >> q;
    // plays is prefix arr, lengths plain
    fenwick_tree plays(MXQ), lengths(MXQ);
    map<string,int> id;
    map<string,ll> deleted;
    ll length = 0; int ind = 0;
    for(int i = 0; i < q; ++i) {
        char c; cin >> ws >> c;
        if(c == 'P') {
            int t; cin >> t;
            if(t >= length) {
                plays.add(1, t / length);
                plays.add(ind + 1, -(t / length));
                t %= length;
            }
            if(t >= lengths.sum(ind, ind)) {
                int l = 1, r = ind;
                while(r > l) {
                    int m = l + (r - l) / 2;
                    ll fm = lengths.sum(m, ind);
                    if(fm > t) l = m + 1;
                    else r = m;
                }
                plays.add(l, 1);
                plays.add(ind + 1, -1);
            }
        } else if(c == 'L') {
            string s; int ln; 
            cin >> s >> ln;
            if(id.count(s)) {
                ll play = plays.sum(1, id[s]);
                deleted.insert(make_pair(s, play));
                ll time = lengths.sum(id[s], id[s]);
                length -= time;
                lengths.add(id[s], -time);
                id.erase(s);
            } else {
                ind++;
                id[s] = ind;
                lengths.add(ind, ln);
                if(deleted.count(s)) {
                    plays.add(ind, deleted[s]);
                    plays.add(ind + 1, -deleted[s]);
                    deleted.erase(s);
                }
                length += ln;
            }
        } else {
            string s; cin >> s;
            if(id.count(s)) {
                cout << plays.sum(1, id[s]) << '\n';
            } else if(deleted.count(s)) {
                cout << deleted[s] << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }
}

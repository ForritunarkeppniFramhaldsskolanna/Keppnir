#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

const int mxn = 1e4;
int eratos[mxn + 1];

void calc() {
    memset(eratos, -1, sizeof(eratos));
    for(int i = 2; i <= mxn; ++i) {
        if(eratos[i] == -1) eratos[i] = i;
        else continue;
        for(int j = i * i; j <= mxn; j += i) {
            eratos[j] = i;
        }
    }
}

vi divisors(int x) {
    if(x == 1) return vi({1});
    int p = eratos[x], e = 0;
    while(x % p == 0) x /= p, e++;
    vi res;
    for(int d : divisors(x)) {
        int pe = 1;
        for(int i = 0; i <= e; ++i) {
            res.push_back(d * pe);
            pe *= p;
        }
    }
    return res;
}

int main() {
    calc();
    int tstn; cin >> tstn;
    map<int,int> pick2pick;
    map<ii,int> picked;
    vector<ii> pickb;
    set<int> taken;
    for(int p = tstn; p >= 2; --p) {
        if(eratos[p] != p) continue;
        for(int i = tstn; i >= 1; --i) {
            if(i % p != 0) continue;
            if(taken.count(i)) continue;
            if(taken.count(i / p)) continue;
            int x = picked.size();
            picked[ii(i / p, i)] = x;
            pickb.push_back(ii(i / p, i));
            pick2pick[i] = i / p;
            pick2pick[i / p] = i;
            taken.insert(i);
            taken.insert(i / p);
        }
    }
    vvi g(picked.size());
    for(auto val : picked) {
        int ind = val.second;
        int x = val.first.first, y = val.first.second;
        for(int z : divisors(y)) {
            if(z == y || z == x) continue;
            if(!pick2pick.count(z)) continue;
            int z2 = pick2pick[z];
            if(z2 < z) swap(z, z2);
            int ind2 = picked[ii(z, z2)];
            g[ind].push_back(ind2);
        }
    }
    vi indeg(picked.size()), q;
    for(int i = 0; i < g.size(); ++i) {
        for(int j : g[i]) indeg[j]++;
    }
    for(int i = 0; i < g.size(); ++i) {
        if(indeg[i] == 0) q.push_back(i);
    }
    vector<ii> pickord;
    while(q.size() > 0) {
        int cur = q.back();
        pickord.push_back(pickb[cur]);
        q.pop_back();
        for(int x : g[cur]) {
            indeg[x]--;
            if(indeg[x] == 0) q.push_back(x);
        }
    }
    bool valid = true;
    for(int i = 0; i < g.size(); ++i) {
        if(indeg[i] > 0) {
            valid = false;
        }
    }
    reverse(pickord.begin(), pickord.end());
    if(valid) {
        cout << pickord.size() << '\n';
        for(int i = 0; i < pickord.size(); ++i) {
            cout << pickord[i].second;
            if(i != pickord.size() - 1) cout << ' ';
        }
        cout << '\n';
    }
}


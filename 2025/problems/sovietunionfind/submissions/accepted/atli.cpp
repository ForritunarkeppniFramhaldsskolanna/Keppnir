#include<cassert>
#include<iostream>
#include<list>
#include<vector>
using namespace std;
typedef vector<int> vi;

struct sovietuf {
    vi p; vector<list<int>> mem;
    sovietuf(int n) : p(n, -1) {
        mem = vector<list<int>>(n);
        for(int i = 0; i < n; ++i)
            mem[i].push_back(i);
    }
    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    void unite(int x, int y) {
        int a = find(x), b = find(y);
        if(a == b) return;
        bool swp = false;
        if(p[a] > p[b]) swap(a, b), swp = true;
        p[a] += p[b];
        p[b] = a;
        if(swp) {
            mem[a].splice(mem[a].begin(), mem[b]);
        } else {
            mem[a].splice(mem[a].end(), mem[b]);
        }
    }
    void balkanise(int x) {
        int a = find(x);
        vi todo(mem[a].begin(), mem[a].end());
        for(int y : todo) {
            p[y] = -1;
            mem[y] = list<int>();
            mem[y].push_back(y);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n >> q;
    sovietuf suf(n);
    while(q--) {
        char op;
        cin >> ws >> op;
        if(op == 'a') {
            int x, y;
            cin >> x >> y;
            x--; y--;
            suf.unite(x, y);
        } else if(op == 'b') {
            int x; cin >> x; x--;
            suf.balkanise(x);
        } else if(op == 'c') {
            int x; cin >> x; x--;
            int p = suf.find(x);
            cout << *suf.mem[p].begin() + 1 << '\n';
        } else assert(false);
    }
}

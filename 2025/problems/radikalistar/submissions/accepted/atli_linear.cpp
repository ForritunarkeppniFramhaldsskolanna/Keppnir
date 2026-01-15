#include<cassert>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;

struct partition_refinement {
    int *locs, *ord_elem, *set_ind, *sent, nonz;
    vector<pair<int,int>> ranges;
    vector<int> reuse;

    partition_refinement(int n) : ranges(1, make_pair(0, n - 1)) {
        nonz = 1;
        locs = new int[n];
        ord_elem = new int[n];
        set_ind = new int[n];
        sent = new int[n];
        memset(set_ind, 0, n * sizeof(int));
        memset(sent, -1, n * sizeof(int));
        for(int i = 0; i < n; ++i) ord_elem[i] = locs[i] = i;
    }

    ~partition_refinement() {
        delete[] locs;
        delete[] ord_elem;
        delete[] set_ind;
        delete[] sent;
    }

    void refine(vector<int>::iterator xb, vector<int>::iterator xe) {
        vector<int> to_fix;
        for(auto it = xb; it != xe; ++it) {
            int ind = set_ind[*it];
            int sz = ranges[ind].second - ranges[ind].first + 1;
            if(sz == 1 && sent[ind] == -1) continue;
            if(sent[ind] == -1) {
                to_fix.push_back(ind);
                int new_ind = ranges.size();
                nonz++;
                if(reuse.size() > 0) {
                    new_ind = reuse.back();
                    reuse.pop_back();
                } else ranges.emplace_back(-1, -1);
                ranges[new_ind] = make_pair(ranges[ind].second + 1, ranges[ind].second);
                sent[ind] = new_ind;
            }
            ranges[sent[ind]].first--;
            ranges[ind].second--;
            if(ranges[ind].second < ranges[ind].first)
                reuse.push_back(ind), nonz--;
            int to_swp = ord_elem[ranges[sent[ind]].first];
            swap(locs[*it], locs[to_swp]);
            swap(ord_elem[locs[*it]], ord_elem[locs[to_swp]]);
            set_ind[*it] = sent[ind];
        }
        for(int x : to_fix) {
            sent[x] = -1;
        }
    }

    void print_group(int x) {
        int s = set_ind[x];
        for(int i = ranges[s].first; i <= ranges[s].second; ++i) {
            cout << ord_elem[i] + 1;
            if(i != ranges[s].second) cout << ' ';
            else cout << '\n';
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    partition_refinement pr(n);
    while(q--) {
        char op;
        cin >> ws >> op;
        if(op == 'r') {
            int m; cin >> m;
            vector<int> ref(m);
            for(int i = 0; i < m; ++i)
                cin >> ref[i], ref[i]--;
            pr.refine(ref.begin(), ref.end());
        } else if(op == 's') {
            cout << pr.nonz << '\n';
        } else if(op == 'm') {
            int x; cin >> x; x--;
            pr.print_group(x);
        } else assert(false);
    }
}

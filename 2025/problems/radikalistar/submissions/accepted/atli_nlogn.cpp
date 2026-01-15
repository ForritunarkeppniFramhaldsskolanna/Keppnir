#include<vector>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct partition_refinement {
    int *locs, *ord_elem, *set_ind;
    vector<pair<int,int>> ranges;

    partition_refinement(int n) : ranges(1, make_pair(0, n - 1)) {
        locs = new int[n];
        ord_elem = new int[n];
        set_ind = new int[n];
        memset(set_ind, 0, n * sizeof(int));
        for(int i = 0; i < n; ++i) ord_elem[i] = locs[i] = i;
    }

    ~partition_refinement() {
        delete[] locs;
        delete[] ord_elem;
        delete[] set_ind;
    }

    void refine(vector<int>::iterator xb, vector<int>::iterator xe) {
        vector<pair<int,int>> hit;
        for(auto it = xb; it != xe; ++it) {
            hit.emplace_back(set_ind[*it], *it);
        }
        sort(hit.begin(), hit.end());
        for(int i = 0, j = 0; i < hit.size(); i = j + 1) {
            while(j + 1 < hit.size() && hit[j + 1].first == hit[i].first) j++;
            int ind = hit[i].first;
            int sz = ranges[ind].second - ranges[ind].first + 1;
            int to_move = j - i + 1;
            if(sz == to_move) continue;
            for(int k = i; k <= j; ++k) {
                locs[ord_elem[ranges[ind].second]] = locs[hit[k].second];
                swap(ord_elem[locs[hit[k].second]], ord_elem[ranges[ind].second]);
                locs[hit[k].second] = ranges[ind].second;
                ranges[ind].second--;
            }
            for(int k = ranges[ind].second + 1; k <= ranges[ind].second + to_move; ++k) {
                set_ind[ord_elem[k]] = ranges.size();
            }
            ranges.push_back(make_pair(ranges[ind].second + 1, ranges[ind].second + to_move));
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
            cout << pr.ranges.size() << '\n';
        } else if(op == 'm') {
            int x; cin >> x; x--;
            pr.print_group(x);
        } else assert(false);
    }
}

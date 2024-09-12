#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef pair<long long,long long> ii;

#define ordered_set tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, q; cin >> n >> q;
    map<string,int> name2ind;
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        name2ind[s] = i;
    }
    vector<long long> scores(n, 0);
    ordered_set ranking;
    for(int i = 0; i < n; ++i)
        ranking.insert(make_pair(0, i));
    while(q--) {
        char op; cin >> ws >> op;
        if(op == '?') {
            string x; cin >> x;
            int ind = name2ind[x];
            cout << ranking.order_of_key(make_pair(scores[ind], -1)) + 1 << ' ' << scores[ind] << '\n';
        } else {
            int k; cin >> k;
            while(k--) {
                string nam; int x;
                cin >> nam >> x;
                int ind = name2ind[nam];
                ranking.erase(make_pair(scores[ind], ind));
                scores[ind] += x;
                ranking.insert(make_pair(scores[ind], ind));
            }
        }
    }
}

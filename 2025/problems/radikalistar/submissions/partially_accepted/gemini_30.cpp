#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    // Initially, everyone is in the same group (group ID 0).
    unordered_map<int, int> member_to_group;
    for (int i = 1; i <= n; ++i) {
        member_to_group[i] = 0;
    }

    unordered_map<int, unordered_set<int>> groups;
    groups[0].insert(1);
    for (int i = 2; i <= n; ++i){
        groups[0].insert(i);
    }
    
    int next_group_id = 1;

    for (int i = 0; i < q; ++i) {
        char type;
        cin >> type;

        if (type == 'r') {
            int t;
            cin >> t;
            vector<int> radicals(t);
            for (int j = 0; j < t; ++j) {
                cin >> radicals[j];
            }

            unordered_map<int, int> old_group_to_new_group;

            for (int radical : radicals) {
                int old_group_id = member_to_group[radical];

                if (old_group_to_new_group.find(old_group_id) == old_group_to_new_group.end()) {
                    old_group_to_new_group[old_group_id] = next_group_id++;
                }

                int new_group_id = old_group_to_new_group[old_group_id];

                groups[old_group_id].erase(radical);
                groups[new_group_id].insert(radical);
                member_to_group[radical] = new_group_id;
             }
             
             vector<int> empty_groups;
             for(auto const& [group_id, members] : groups){
                 if (members.empty()){
                     empty_groups.push_back(group_id);
                 }
             }
             for (int empty_group_id : empty_groups){
                 groups.erase(empty_group_id);
             }

        } else if (type == 's') {
            int num_groups = 0;
            for (auto const& [group_id, members] : groups)
            {
              if (!members.empty()) num_groups++;
            }
            cout << num_groups << endl;

        } else if (type == 'm') {
            int u;
            cin >> u;
            int group_id = member_to_group[u];
            for (int member : groups[group_id]) {
                cout << member << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

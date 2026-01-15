#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> supervisors(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> supervisors[i];
    }

    set<int> available_ids;
    for (int i = n + 1; i <= 2 * n; ++i) {
        available_ids.insert(i);
    }

    vector<bool> employed(400001, false);
    for(int i = 1; i <=n; ++i){
        employed[i] = true;
    }
    
    vector<int> current_supervisors = supervisors;

    for (int i = 0; i < q; ++i) {
        char query_type;
        int x;
        cin >> query_type >> x;

        if (query_type == '+') {
            int new_employee_id;
            if (!available_ids.empty()) {
                new_employee_id = *available_ids.begin();
                available_ids.erase(available_ids.begin());
            } else {
                new_employee_id = n + 1;
                for (int j = n+1; j <= 400000; j++){
                    if (!employed[j]){
                        new_employee_id = j;
                        break;
                    }
                }
                
            }
            current_supervisors.resize(max((int)current_supervisors.size(), new_employee_id + 1));
            current_supervisors[new_employee_id] = x;
            employed[new_employee_id] = true;
        } else if (query_type == '-') {
            available_ids.insert(x);
            employed[x] = false;

            for (int j = 1; j < current_supervisors.size(); ++j) {
                if (current_supervisors[j] == x) {
                    current_supervisors[j] = current_supervisors[x];
                }
            }
        } else if (query_type == '?') {
            cout << current_supervisors[x] << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int find_set(vector<int>& parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find_set(parent, parent[i]);
}

void union_sets(vector<int>& parent, int a, int b) {
    a = find_set(parent, a);
    b = find_set(parent, b);
    if (a != b)
        parent[b] = a;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> parent(n + 1);
    iota(parent.begin(), parent.end(), 0);

    for (int i = 0; i < q; ++i) {
        char type;
        cin >> type;

        if (type == 'a') {
            int x, y;
            cin >> x >> y;
            union_sets(parent, x, y);
        } else if (type == 'b') {
            int x;
            cin >> x;
            int ruler = find_set(parent, x);
            for (int j = 1; j <= n; ++j) {
                if (find_set(parent, j) == ruler) {
                    parent[j] = j;
                }
            }
        } else if (type == 'c') {
            int x;
            cin >> x;
            cout << find_set(parent, x) << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <tuple>
#include <climits>

using namespace std;

int main() {
    int A, X;
    cin >> A >> X;

    vector<tuple<char, int, int>> operations(A);
    for (int i = 0; i < A; ++i) {
        cin >> get(operations[i]) >> get(operations[i]) >> get(operations[i]);
    }

    map<int, int> dist;
    dist[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        if (u == X) {
            cout << d << endl;
            return 0;
        }

        for (const auto& op : operations) {
            char op_type = get(op);
            int y = get(op);
            int c = get(op);

            int next_val = -1;
            if (op_type == '+') {
                next_val = u + y;
            } else if (op_type == '-') {
                next_val = u - y;
            } else if (op_type == '*') {
                next_val = u * y;
            } else if (op_type == '/') {
                if (y != 0) {
                    next_val = u / y;
                }
            }

            if (next_val >= 0 && next_val < 100000000) {
                if (dist.find(next_val) == dist.end() || dist[next_val] > d + c) {
                    dist[next_val] = d + c;
                    pq.push({d + c, next_val});
                }
            }
        }
    }

    cout << "Engin leid!" << endl;

    return 0;
}

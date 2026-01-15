#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
 
// Structure for an operation.
struct Operation {
    char op;
    int y;
    int cost;
};
 
// Apply an operation on the current state.
// Returns -1 if the result is invalid (negative or >= 100,000,000).
int applyOp(int curr, const Operation &oper) {
    long long nxt;
    switch(oper.op){
        case '+':
            nxt = (long long) curr + oper.y;
            if(nxt >= 100000000) return -1;
            return (int)nxt;
        case '-':
            nxt = (long long) curr - oper.y;
            if(nxt < 0) return -1;
            return (int)nxt;
        case '*':
            nxt = (long long) curr * oper.y;
            if(nxt >= 100000000) return -1;
            return (int)nxt;
        case '/':
            // Division by y (nonzero) – integer division.
            nxt = curr / oper.y;
            return (int)nxt;
    }
    return -1;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int A, X;
    cin >> A >> X;
    vector<Operation> ops(A);
    for (int i = 0; i < A; i++){
        cin >> ops[i].op >> ops[i].y >> ops[i].cost;
    }
 
    // Special case: if X is 0, we're already there.
    if(X == 0){
        cout << 0 << "\n";
        return 0;
    }
 
    // Dijkstra's algorithm:
    // We use a min-heap priority queue that stores pairs (total_cost, state)
    // and an unordered_map to record the best (minimum) cost at which a state was reached.
    const int INF = 0x3f3f3f3f;
    unordered_map<int,int> dist;
    dist.reserve(10000); // Reserve some initial capacity.
    dist[0] = 0;
 
    typedef pair<int,int> pii;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
 
    while(!pq.empty()){
        auto [d, state] = pq.top();
        pq.pop();
 
        // Skip this entry if we have already found a better cost for this state.
        if(dist.find(state) == dist.end() || d != dist[state])
            continue;
 
        // If we have reached the target number X, output the cost.
        if(state == X){
            cout << d << "\n";
            return 0;
        }
 
        // Try all allowed operations from the current state.
        for(auto &op : ops){
            int nxt = applyOp(state, op);
            if(nxt < 0) continue; // illegal operation: skip.
            int nd = d + op.cost;
            if(dist.find(nxt) == dist.end() || nd < dist[nxt]){
                dist[nxt] = nd;
                pq.push({nd, nxt});
            }
        }
    }
 
    // If we never reached state X, then it's impossible.
    cout << "Engin leid!" << "\n";
    return 0;
}


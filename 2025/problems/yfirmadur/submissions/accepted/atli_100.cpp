#include<iostream>
#include<cassert>
#include<vector>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> avail;

int get_new_num() {
    int x = avail.top();
    avail.pop();
    if(avail.empty()) {
        avail.push(x + 1);
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n >> q;
    avail.push(n);
    vector<bool> working(n, true);
    vector<int> parent(n), index(n), number(n);
    for(int i = 0; i < n; ++i)
        cin >> parent[i], parent[i]--;
    for(int i = 0; i < n; ++i)
        index[i] = number[i] = i;
    while(q--) {
        char op; int x;
        cin >> ws >> op >> x;
        x--;
        if(op == '+') {
            int y = get_new_num();
            if(y >= index.size())
                index.push_back(working.size());
            else
                index[y] = working.size();
            working.push_back(true);
            parent.push_back(index[x]);
            number.push_back(y);
        } else if(op == '-') {
            avail.push(x);
            working[index[x]] = false;
        } else if(op == '?') {
            x = index[x];
            int ans = parent[x];
            while(!working[ans])
                ans = parent[ans];
            int fix = parent[x];
            parent[x] = ans;
            while(!working[fix]) {
                int tmp = parent[fix];
                parent[fix] = ans;
                fix = tmp;
            }
            // each edge only traveled once if it corresponds
            // to being removed. thus this is fast amortized
            cout << number[ans] + 1 << '\n';
        } else {
            assert(false);
        }
    }
}

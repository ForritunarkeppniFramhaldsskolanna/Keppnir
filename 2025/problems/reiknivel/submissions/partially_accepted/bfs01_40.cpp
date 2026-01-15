#include<deque>
#include<cstring>
#include<iostream>
using namespace std;

const int MAX_X = 100000000;
const int MAX_K = 3;
const int MAX_A = 5;
int dist[MAX_X];
bool done[MAX_X];
char op[MAX_A];
int arg[MAX_A], cost[MAX_A];

int main() {
    memset(dist, -1, sizeof(dist));
    memset(done, 0, sizeof(done));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, x; cin >> a >> x;
    deque<int> q;
    for(int i = 0; i < a; ++i) {
        cin >> ws >> op[i] >> arg[i] >> cost[i];
    }
    dist[0] = 0;
    q.push_back(0);
    while(q.size() > 0) {
        int cur = q.front();
        q.pop_front();
        if(done[cur]) continue;
        done[cur] = true;
        for(int i = 0; i < a; ++i) {
            int z = cur;
            if(op[i] == '+') z += arg[i];
            if(op[i] == '*') z *= arg[i];
            if(op[i] == '-') z -= arg[i];
            if(op[i] == '/') z /= arg[i];
            if(z >= MAX_X) continue;
            if(z < 0) continue;
            if(dist[z] == -1 || 
                dist[z] > dist[cur] + cost[i]) {
                dist[z] = dist[cur] + cost[i];
                if(cost[i] == 0) q.push_front(z);
                else q.push_back(z);
            }
        }
    }
    if(dist[x] == -1) cout << "Engin leid!\n";
    else cout << dist[x] << '\n';
}

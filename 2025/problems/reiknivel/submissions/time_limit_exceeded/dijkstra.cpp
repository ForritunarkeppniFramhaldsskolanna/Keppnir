#include<queue>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
typedef pair<int,int> ii;

const int MAX_X = 100000000;
const int MAX_K = 3;
const int MAX_A = 5;
const int MOD = MAX_K + 1;
int dist[MAX_X];
char op[MAX_A];
int arg[MAX_A], cost[MAX_A];

int main() {
    memset(dist, -1, sizeof(dist));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, x; cin >> a >> x;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for(int i = 0; i < a; ++i)
        cin >> ws >> op[i] >> arg[i] >> cost[i];
    pq.push(ii(0, 0));
    dist[0] = 0;
    while(pq.size() > 0) {
        int cur = pq.top().second;
        int curw = pq.top().first;
        pq.pop();
        if(dist[cur] != curw) continue;
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
                pq.push(ii(dist[z], z));
            }
        }
    }
    if(dist[x] == -1) cout << "Engin leid!\n";
    else cout << dist[x] << '\n';
}

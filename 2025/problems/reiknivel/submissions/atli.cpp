#include<queue>
#include<cstring>
#include<iostream>
using namespace std;

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
    queue<int> q[MAX_K + 1];
    for(int i = 0; i <= MAX_K; ++i)
        q[i] = queue<int>();
    for(int i = 0; i < a; ++i)
        cin >> ws >> op[i] >> arg[i] >> cost[i];
    q[0].push(0);
    dist[0] = 0;
    int pos = 0, left = 1;
    while(left > 0) {
        while(q[pos % MOD].empty()) pos++;
        pos %= MOD;
        int cur = q[pos].front();
        q[pos].pop();
        left--;
        if(dist[cur] % MOD != pos) continue;
        if(cur == x) {
            cout << dist[x] << '\n';
            return 0;
        }
        for(int i = 0; i < a; ++i) {
            long long z = cur;
            if(op[i] == '+') z += arg[i];
            if(op[i] == '*') z *= arg[i];
            if(op[i] == '-') z -= arg[i];
            if(op[i] == '/') z /= arg[i];
            if(z >= MAX_X) continue;
            if(z < 0) continue;
            if(dist[z] == -1 || 
                dist[z] > dist[cur] + cost[i]) {
                dist[z] = dist[cur] + cost[i];
                q[dist[z] % MOD].push(z);
                left++;
            }
        }
    }
    if(dist[x] == -1) cout << "Engin leid!\n";
    else cout << dist[x] << '\n';
}

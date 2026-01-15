#include<cstring>
#include<iostream>
#include<queue>
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
    bool monotone = true;
    for(int i = 0; i < a; ++i) {
        cin >> ws >> op[i] >> arg[i] >> cost[i];
        monotone &= op[i] != '/';
        monotone &= op[i] != '-';
    }
    dist[0] = 0;
    if(monotone) {
        for(int i = 1; i <= x; ++i) {
            for(int j = 0; j < a; ++j) {
                if(op[j] == '*' && arg[j] == 0)
                    continue;
                if(op[j] == '*' && i % arg[j] != 0) 
                    continue;
                int sub = op[j] == '+' ? i - arg[j] : i / arg[j];
                if(sub < 0 || sub >= i) continue;
                if(dist[sub] == -1) continue;
                int curcost = dist[sub] + cost[j];
                if(dist[i] == -1) dist[i] = curcost;
                else dist[i] = min(dist[i], curcost);
            }
        }
    } else {
        deque<int> q;
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
    }
    if(dist[x] == -1) cout << "Engin leid!\n";
    else cout << dist[x] << '\n';
}

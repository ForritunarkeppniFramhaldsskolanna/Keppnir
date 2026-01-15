#include<cstring>
#include<iostream>
#include<map>
using namespace std;

const int MAX_X = 100000000;
const int MAX_K = 3;
const int MAX_A = 5;
int dist[MAX_X];
char op[MAX_A];
int arg[MAX_A], cost[MAX_A];

int main() {
    memset(dist, -1, sizeof(dist));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, x; cin >> a >> x;
    map<int,int> addcost, mulcost;
    for(int i = 0; i < a; ++i) {
        cin >> ws >> op[i] >> arg[i] >> cost[i];
        if(op[i] == '+') {
            if(addcost.count(arg[i]))
                addcost[arg[i]] = min(addcost[arg[i]], cost[i]);
            else addcost[arg[i]] = cost[i];
        } else {
            if(mulcost.count(arg[i]))
                mulcost[arg[i]] = min(mulcost[arg[i]], cost[i]);
            else mulcost[arg[i]] = cost[i];
        }
    }
    dist[0] = 0;
    for(int i = 1; i <= x; ++i) {
        for(int j = 1; j <= i; ++j) {
            if(dist[i - j] == -1) continue;
            if(!addcost.count(j)) continue;
            int sub = dist[i - j] + addcost[j];
            if(dist[i] == -1) dist[i] = sub;
            else dist[i] = min(dist[i], sub);
        }
        for(int j = 2; j <= i; ++j) {
            if(i % j != 0) continue;
            if(dist[i / j] == -1) continue;
            if(!mulcost.count(j)) continue;
            int sub = dist[i / j] + mulcost[j];
            if(dist[i] == -1) dist[i] = sub;
            else dist[i] = min(dist[i], sub);
        }
    }
    if(dist[x] == -1) cout << "Engin leid!\n";
    else cout << dist[x] << '\n';
}

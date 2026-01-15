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
    for(int i = 0; i < a; ++i) {
        cin >> ws >> op[i] >> arg[i] >> cost[i];
    }
    dist[0] = 0;
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
    if(dist[x] == -1) cout << "Engin leid!\n";
    else cout << dist[x] << '\n';
}

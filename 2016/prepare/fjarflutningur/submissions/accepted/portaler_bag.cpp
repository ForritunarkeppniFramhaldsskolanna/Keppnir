#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T &x) { return x.size(); }

// assert or gtfo

#define WHITE 0
#define GRAY 1
#define BLACK 2

int *state, *nxt;
int get_cycle(int v) {
    if (state[v] == BLACK)
        return -1;
    if (state[v] == GRAY)
        return v;
    state[v] = GRAY;
    int res = get_cycle(nxt[v]);
    state[v] = BLACK;
    return res;
}

int main()
{
    int n;
    scanf("%d\n", &n);

    nxt = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d\n", nxt + i);
        nxt[i]--;
    }

    state = new int[n];
    memset(state, WHITE, n << 2);

    int cycles = 0;
    int *cycle = new int[n];
    int *cycle_at = new int[n];
    memset(cycle, -1, n << 2);
    int *cycle_len = new int[n];

    for (int i = 0; i < n; i++) {
        if (state[i] != WHITE)
            continue;

        int u = get_cycle(i);
        if (u == -1)
            continue;

        int cur = u;
        int idx = 0;
        do {
            cycle[cur] = cycles;
            cycle_at[cur] = idx++;
            cur = nxt[cur];
        } while (cur != u);

        cycle_len[cycles] = idx;
        cycles++;
    }

    vi *children = new vi[n];
    for (int i = 0; i < n; i++) {
        if (cycle[i] != -1)
            continue;

        children[nxt[i]].push_back(i);
    }

    int *chain_end = new int[n];
    int *chain_depth = new int[n];
    for (int i = 0; i < n; i++) {
        if (cycle[i] == -1)
            continue;

        queue<ii> Q;
        Q.push(ii(i, 0));

        while (!Q.empty()) {
            ii cur = Q.front();
            Q.pop();
            chain_depth[cur.first] = cur.second;
            chain_end[cur.first] = i;
            for (int j = 0; j < size(children[cur.first]); j++) {
                Q.push(ii(children[cur.first][j], 1 + cur.second));
            }
        }
    }

    int qs;
    scanf("%d\n", &qs);

    vii *v_queries = new vii[n];
    bool *answer = new bool[qs];

    vii queries(qs);
    for (int q = 0; q < qs; q++) {
        int a, b;
        scanf("%d %d\n", &a, &b);
        a--, b--;
        queries[q] = ii(a, b);
        v_queries[a].push_back(ii(b, q));
        answer[q] = false;
    }

    bool *in_dfs = new bool[n];
    memset(in_dfs, 0, n);

    for (int i = 0; i < n; i++) {
        if (cycle[i] == -1)
            continue;

        stack<int> S;
        S.push(i);

        while (!S.empty()) {
            int cur = S.top();

            if (in_dfs[cur]) {
                S.pop();
                in_dfs[cur] = false;
            } else {

                in_dfs[cur] = true;

                for (int i = 0; i < size(v_queries[cur]); i++) {
                    ii v = v_queries[cur][i];
                    if (in_dfs[v.first]) {
                        answer[v.second] = true;
                    }
                }

                for (int i = 0; i < size(children[cur]); i++) {
                    S.push(children[cur][i]);
                }
            }
        }
    }

    for (int q = 0; q < qs; q++) {
        int a = queries[q].first,
            b = queries[q].second;

        bool a_in_cycle = cycle[a] != -1,
             b_in_cycle = cycle[b] != -1;

        if (a_in_cycle && b_in_cycle) {
            if (cycle[a] == cycle[b]) {
                printf("%d\n", (cycle_at[b] - cycle_at[a] + cycle_len[cycle[a]]) % cycle_len[cycle[a]]);
            } else {
                printf("-1\n");
            }
        } else if (a_in_cycle && !b_in_cycle) {
            printf("-1\n");
        } else if (!a_in_cycle && b_in_cycle) {
            if (cycle[chain_end[a]] == cycle[b]) {
                printf("%d\n", chain_depth[a] + (cycle_at[b] - cycle_at[chain_end[a]] + cycle_len[cycle[b]]) % cycle_len[cycle[b]]);
            } else {
                printf("-1\n");
            }
        } else if (!a_in_cycle && !b_in_cycle) {
            if (chain_end[a] == chain_end[b]) {
                if (answer[q]) {
                    printf("%d\n", chain_depth[a] - chain_depth[b]);
                } else {
                    printf("-1\n");
                }
            } else {
                printf("-1\n");
            }
        } else {
            assert(false);
        }
    }

    return 0;
}


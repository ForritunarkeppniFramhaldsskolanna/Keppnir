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

int mod = 1000000007;
map<vi, int> mem;

int dp(vi at) {
    bool zero = true;
    for (int i = 0; i < size(at); i++)
        if (at[i] > 0) {
            zero = false;
            break;
        }

    if (zero)
        return 1;
    if (mem.find(at) != mem.end())
        return mem[at];

    int sum = 0;
    for (int i = 0; i < size(at); i++) {
        if (at[i] == 0) continue;
        vi nxt(at);
        nxt[i]--;
        sum += dp(nxt);
        if (sum >= mod)
            sum -= mod;
    }

    return mem[at] = sum;
}

int main()
{
    int n;
    cin >> n;

    vi start(n);
    for (int i = 0; i < n; i++)
        cin >> start[i];

    cout << dp(start) << endl;

    return 0;
}


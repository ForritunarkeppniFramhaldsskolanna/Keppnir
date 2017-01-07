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

int main() {

    ll k;
    cin >> k;

    queue<ll> Q;
    Q.push(4);
    Q.push(7);

    while (!Q.empty()) {
        ll cur = Q.front(); Q.pop();

        if (--k == 0) {
            cout << cur << endl;
            break;
        }

        Q.push(cur * 10 + 4);
        Q.push(cur * 10 + 7);
    }

    return 0;
}


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

int main()
{
    int k;
    cin >> k;

    ll mn = -1,
       mx = (1L<<30) + 1;

    for (int i = 0; i < k; i++) {
        string op;
        ll x;
        cin >> op >> op >> x;
        if (op == "<") {
            mx = min(mx, x - 1);
        } else if (op == "<=") {
            mx = min(mx, x);
        } else if (op == ">") {
            mn = max(mn, x + 1);
        } else if (op == ">=") {
            mn = max(mn, x);
        } else {
            assert(false);
        }
    }

    assert(mn >= 0);
    assert(mx <= (1L<<30));
    assert(mx - mn + 1 <= 1000);
    assert(mx - mn + 1 >= 1);

    for (int i = mn; i <= mx; i++) {
        cout << i << endl;
    }

    return 0;
}


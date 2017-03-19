#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
#include <cassert>
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
template <class T> int size(T x) { return x.size(); }

// assert or gtfo

int main()
{
    ll k;
    cin >> k;

    for (ll x = 1; ; x++)
    {
        bool found = false;
        ll t = x;
        while (t)
        {
            found = found || (t % 10) == 0 || (t % 10) == 8;
            t /= 10;
        }

        if (found)
            continue;

        if (--k == 0)
        {
            cout << x << endl;
            break;
        }
    }

    return 0;
}


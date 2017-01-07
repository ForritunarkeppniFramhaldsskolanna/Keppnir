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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    ll n, x, y;
    cin >> n >> x >> y;

    ll cnt = 0;
    for (ll i = x; i <= n; i += x) {
        cnt++;
    }
    for (ll i = y; i <= n; i += y) {
        cnt++;
    }

    ll z = x / gcd(x, y) * y;
    for (ll i = z; i <= n; i += z) {
        cnt--;
    }

    cout << cnt << endl;

    return 0;
}


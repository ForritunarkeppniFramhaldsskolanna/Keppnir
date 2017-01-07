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

ll parse_size(string s) {
    ll x = 0;
    for (int i = 0; i < size(s); i++) {
        if (s[i] == 'B') {
            return x;
        } else if (s[i] == 'K') {
            return x * 1024;
        } else if (s[i] == 'M') {
            return x * 1024 * 1024;
        } else if (s[i] == 'G') {
            return x * 1024 * 1024 * 1024;
        } else {
            x = x * 10 + s[i] - '0';
        }
    }
    assert(false);
}

int main()
{
    int n, m;
    cin >> n >> m;

    ll sm = 0;
    for (int i = 0; i < n; i++) {
        string sz;
        cin >> sz >> sz;
        sm += parse_size(sz);
    }

    ll mn;
    string mns;
    bool found = false;
    for (int i = 0; i < m; i++) {
        string name, sz;
        int price;
        cin >> name >> sz >> price;
        ll z = parse_size(sz);
        if (z <= sm) continue;
        if (!found || price < mn) {
            mn = price;
            mns = name;
            found = true;
        }
    }

    cout << mns << endl;

    return 0;
}


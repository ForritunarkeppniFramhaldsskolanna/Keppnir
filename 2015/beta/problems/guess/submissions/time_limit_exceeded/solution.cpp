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

    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int k;
    cin >> k;

    vector<pair<string, int> > ops;

    for (int i = 0; i < k; i++) {
        string op;
        ll x;
        cin >> op >> op >> x;
        ops.push_back(make_pair(op, x));
    }

    for (int x = 0; x <= (1L<<30); x++) {
        bool ok = true;
        for (int j = 0; ok && j < size(ops); j++) {
            if (ops[j].first == ">") {
                ok = ok && x > ops[j].second;
            } else if (ops[j].first == ">=") {
                ok = ok && x >= ops[j].second;
            } else if (ops[j].first == "<") {
                ok = ok && x < ops[j].second;
            } else if (ops[j].first == "<=") {
                ok = ok && x <= ops[j].second;
            }
        }

        if (ok) {
            cout << x << endl;
        }
    }

    return 0;
}


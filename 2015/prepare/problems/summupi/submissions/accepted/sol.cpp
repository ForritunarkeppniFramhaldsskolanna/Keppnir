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

const string pi = "3.14159265358979323846";

int cmp(const string &a, const string &b) {
    int m = max(size(a), size(b));
    for (int i = 0; i < m; i++) {
        char x = i < size(a) ? a[i] : '0';
        char y = i < size(b) ? b[i] : '0';
        if (x != y) {
            return x < y ? -1 : 1;
        }
    }

    return 0;
}

char tmp[100];
string add(const string &a, const string &b) {
    assert(size(a) == size(b));

    int carry = 0;
    for (int i = size(a) - 1; i >= 0; i--) {
        if (a[i] == '.') {
            tmp[i] = '.';
        } else {
            int cur = (a[i] - '0') + (b[i] - '0') + carry;
            tmp[i] = (cur % 10) + '0';
            carry = cur / 10;
        }
    }

    if (carry > 0) {
        return "";
    }

    return string(tmp, tmp + size(a));
}

vector<string> arr;

int main() {
    int n;
    cin >> n;
    arr = vector<string>(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n == 1) {
        if (cmp(arr[0], pi) <= 0) {
            cout << arr[0] << endl;
        } else {
            cout << "0.0000000000" << endl;
        }

        return 0;
    }

    int l = n / 2,
        r = n - l;

    string best = "0.0000000000";

    set<string> poss;

    for (int i = 0; i < (1 << l); i++) {
        string cur = "0.0000000000";
        for (int j = 0; j < l; j++) {
            if (i & (1 << j)) {
                cur = add(cur, arr[j]);
                if (cur == "")
                    break;
            }
        }
        if (cur == "")
            continue;

        if (cmp(cur, pi) <= 0) {
            poss.insert(cur);
            if (cmp(cur, best) > 0) {
                best = cur;
            }
        }
    }

    vector<string> lef(poss.begin(), poss.end());

    for (int i = 0; i < (1 << r); i++) {
        string cur = "0.0000000000";
        for (int j = 0; j < r; j++) {
            if (i & (1 << j)) {
                cur = add(cur, arr[l + j]);
                if (cur == "")
                    break;
            }
        }

        if (cur == "")
            continue;

        int lo = 0,
            hi = size(lef) - 1,
            res = -1;

        while (lo <= hi) {
            int m = (lo + hi) / 2;
            string nxt = add(cur, lef[m]);
            if (nxt != "" && cmp(nxt, pi) <= 0) {
                res = m;
                lo = m + 1;
            } else {
                hi = m - 1;
            }
        }

        if (res != -1) {
            string nxt = add(cur, lef[res]);
            if (nxt != "" && cmp(nxt, best) > 0) {
                best = nxt;
            }
        }
    }

    cout << best << endl;

    return 0;
}


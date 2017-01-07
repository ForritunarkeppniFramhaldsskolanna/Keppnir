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
string bt(int at, const string &sum) {
    if (sum == "" || cmp(sum, pi) > 0) {
        return "0.0000000000";
    }
    if (at == size(arr)) {
        return sum;
    }

    string res = bt(at + 1, sum);
    string other = bt(at + 1, add(sum, arr[at]));
    if (cmp(res, other) < 0) {
        res = other;
    }
    return res;
}

int main() {

    int n;
    cin >> n;
    arr = vector<string>(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << bt(0, "0.0000000000") << endl;

    return 0;
}


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

    k--;

    for (int len = 1; ; len++) {
        if (k < (1LL << len)) {
            for (int i = len - 1; i >= 0; i--) {
                if (k & (1LL << i)) {
                    cout << 7;
                } else {
                    cout << 4;
                }
            }

            cout << endl;
            break;
        } else {
            k -= (1LL << len);
        }
    }


    return 0;
}


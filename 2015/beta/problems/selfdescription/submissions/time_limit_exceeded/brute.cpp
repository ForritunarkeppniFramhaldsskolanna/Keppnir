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

int *cur, *tmp;

bool bt(int n, int at) {
    if (at == n) {
        memset(tmp, 0, n << 2);
        for (int i = 0; i < n; i++) {
            tmp[cur[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (cur[i] != tmp[i]) {
                return false;
            }
        }

        for (int i = 0; i < n; i++) {
            if (i != 0) {
                cout << " ";
            }
            cout << cur[i];
        }
        cout << endl;

        return true;

    } else {
        for (int i = 0; i < n; i++) {
            cur[at] = i;
            if (bt(n, at + 1)) {
                return true;
            }
        }
    }


    return false;
}

int main()
{
    int n;
    cin >> n;
    cur = new int[n];
    tmp = new int[n];

    if (!bt(n, 0)) {
        cout << "Engin" << endl;
    }

    return 0;
}


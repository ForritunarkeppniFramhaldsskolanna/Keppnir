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
    int n;
    cin >> n;
    if (n == 0) {
        cout << 10 << endl;
    } else if (n < 10) {
        cout << n << endl;
    } else {

        stack<int> S;
        for (int i = 9; i >= 2; i--) {
            while (n % i == 0) {
                S.push(i);
                n /= i;
            }
        }

        if (n > 1) {
            cout << -1 << endl;
        } else {
            while (!S.empty()) {
                cout << S.top();
                S.pop();
            }

            cout << endl;
        }
    }

    return 0;
}


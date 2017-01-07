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

int n, l;
char found[1000];
int str_k[1000];
string strs[1000];
vi valid[1000];

bool bt(int at) {

    if (at == n) {
        return true;
    } else {

        for (int i = 0; i < size(valid[at]); i++) {
            int curk = valid[at][i];
            vector<int> empty;
            bool ok = true;
            for (int j = 0, now = 0; j < l; j += curk, now++) {
                assert(now < size(strs[at]));

                if (found[j] == '_') {
                    empty.push_back(j);
                    found[j] = strs[at][now];
                } else if (found[j] == strs[at][now]) {

                } else {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                if (bt(at + 1)) {
                    return true;
                }
            }

            for (int j = 0; j < size(empty); j++) {
                found[empty[j]] = '_';
            }
        }

        return false;
    }
}

int main() {

    srand(time(NULL));

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    for (l = 1; ; l++) {
        for (int i = 0; i < n; i++) {
            valid[i].clear();
        }

        for (int k = 1; k <= l; k++) {
            int cnt = (l + k - 1) / k;

            for (int i = 0; i < n; i++) {
                if (cnt == size(strs[i])) {
                    valid[i].push_back(k);
                }
            }
        }

        memset(found, '_', sizeof(found));
        if (bt(0)) {
            for (int i = 0; i < l; i++) {
                if (found[i] == '_') {
                    printf("%c", rand()%26 + 'a');
                } else {
                    printf("%c", found[i]);
                }
            }
            printf("\n");
            break;
        }
    }


    return 0;
}


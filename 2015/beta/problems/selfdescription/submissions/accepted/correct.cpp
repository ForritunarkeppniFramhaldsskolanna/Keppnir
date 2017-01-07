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

int *cur, *cnt;

bool bt(int n, int at) {
    if (at == n) {

        memset(cnt, 0, n << 2);
        for (int i = 0; i < n; i++) {
            cnt[cur[i]]++;
        }

        for (int i = 0; i < n; i++){
            if (cur[i] != cnt[i]) {
                return false;
            }
        }

        for (int i = 0; i < n; i++) {
            if (i != 0) {
                printf(" ");
            }
            printf("%d", cur[i]);
        }

        printf("\n");

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

    if (n <= 7) {

        cur = new int[n];
        cnt = new int[n];

        if (!bt(n, 0)) {
            printf("Engin\n");
        }

    } else {

        printf("%d 2 1", n - 4);

        for (int i = 0; i < n - 7; i++) {
            printf(" 0");
        }

        printf(" 1 0 0 0\n");

    }

    return 0;
}


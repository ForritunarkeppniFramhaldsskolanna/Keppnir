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
template <class T> int size(const T &x) { return x.size(); }

// assert or gtfo

vi describe(const vi &arr) {
    int n = size(arr);
    vi res(n);
    for (int i = 0; i < n; i++) {
        res[arr[i]]++;
    }

    return res;
}

int main()
{
    srand(time(NULL));

    int n;
    cin >> n;

    for (int x = 0; x < 1000; x++) {

        vi cur(n);
        for (int i = 0; i < n; i++) {
            cur[i] = rand() % n;
        }

        for (int y = 0; y < 1000; y++) {

            vi nxt = describe(cur);
            if (cur == nxt) {

                for (int i = 0; i < n; i++) {
                    if (i != 0) {
                        printf(" ");
                    }

                    printf("%d", cur[i]);
                }

                printf("\n");
                return 0;
            }

            cur = nxt;
        }
    }

    printf("Engin\n");

    return 0;
}


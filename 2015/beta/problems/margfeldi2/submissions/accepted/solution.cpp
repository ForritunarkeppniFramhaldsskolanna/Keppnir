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

int main()
{
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("10\n");
        return 0;
    }

    if (n == 1) {
        printf("%d\n", n);
        return 0;
    }

    int t = n;
    for (int i = 2; i < 10; i++) {
        while (t % i == 0) {
            t /= i;
        }
    }

    if (t != 1) {
        printf("-1\n");
        return 0;
    }

    stack<int> S;

    for (int i = 9; i >= 2; i--) {
        while (n % i == 0) {
            S.push(i);
            n /= i;
        }
    }

    while (!S.empty()) {
        printf("%d", S.top());
        S.pop();
    }

    printf("\n");

    return 0;
}


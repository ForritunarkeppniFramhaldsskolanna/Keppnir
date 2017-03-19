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

int dig[8] = {
    1,2,3,4,5,6,7,9
};

int main()
{
    ll n;
    cin >> n;
    n--;

    __int128 p8[35];
    p8[0] = 1;
    for (int i = 1; i < 35; i++)
        p8[i] = 8 * p8[i - 1];

    for (int len = 1; ; len++)
    {
        if (n < p8[len])
        {
            stack<int> res;
            for (int i = 0; i < len; i++)
            {
                res.push(dig[n % 8]);
                n /= 8;
            }

            while (!res.empty())
            {
                printf("%d", res.top());
                res.pop();
            }

            printf("\n");
            break;
        }
        else
        {
            n -= p8[len];
        }
    }

    return 0;
}


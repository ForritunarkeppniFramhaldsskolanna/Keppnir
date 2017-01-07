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
    int k, n;
    cin >> k >> n;

    string s;
    cin >> s;

    for (int i = 0; i < size(s); i++) {
        for (int j = i + 1; j < size(s); j++) {
            bool same = true;

            for (int x = 0; x < n; x++) {
                if (s[(i + x) % size(s)] != s[(j + x) % size(s)]) {
                    same = false;
                    break;
                }
            }

            if (same) {
                printf("Neibb\n");
                return 0;
            }
        }
    }

    printf("De Bruijn\n");

    return 0;
}


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

int arr[4][4];
void rot(int cnt) {
    if (cnt == 0)
        return;

    int tmp[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tmp[i][j] = arr[3 - j][i];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            arr[i][j] = tmp[i][j];

    rot(cnt - 1);
}

int main()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            scanf("%d", &arr[i][j]);

    string s;
    cin >> s;

    map<string, int> dir;
    dir["RIGHT"] = 0;
    dir["UP"] = 1;
    dir["LEFT"] = 2;
    dir["DOWN"] = 3;

    rot(dir[s]);

    for (int i = 0; i < 4; i++) {
        int j = 3;
        while (j >= 0) {
            int k = j-1;
            while (k >= 0 && arr[i][k] == 0) {
                k--;
            }
            if (k < 0) {
                break;
            }

            if (arr[i][j] == 0) {
                arr[i][j] = arr[i][k];
                arr[i][k] = 0;
            } else {
                if (arr[i][j] == arr[i][k]) {
                    arr[i][j] *= 2;
                    arr[i][k] = 0;
                    j--;
                } else {
                    if (k < j - 1) {
                        arr[i][j-1] = arr[i][k];
                        arr[i][k] = 0;
                    }
                    j--;
                }
            }
        }
    }

    rot(4 - dir[s]);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%4d", arr[i][j]);
            printf(" ");
        }
        printf("\n");
    }


    return 0;
}


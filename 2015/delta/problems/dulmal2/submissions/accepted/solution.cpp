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
    srand(time(NULL));

    int k;
    cin >> k;
    string s;
    cin >> s;

    for (int i = 0; i < size(s); i++) {
        cout << s[i];

        int cnt = k - 1;
        if (i == size(s) - 1) {
            cnt = rand() % k;
        }
        for (int j = 0; j < cnt; j++) {
            cout << static_cast<char>('a' + rand() % 26);
        }
    }
    cout << endl;

    return 0;
}


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
    char op;
    scanf("%c ", &op);

    if (op == 't') {
        char c1, c2;
        scanf("%c %c\n", &c1, &c2);

        string line;
        getline(cin, line);

        for (int i = 0; i < size(line); i++) {
            if (line[i] == c1) {
                cout << c2;
            } else {
                cout << line[i];
            }
        }

        cout << endl;

    } else {
        char c1;
        scanf("%c\n", &c1);

        string line;
        getline(cin, line);

        for (int i = 0; i < size(line); i++) {
            if (line[i] == c1) {
            } else {
                cout << line[i];
            }
        }

        cout << endl;
    }

    return 0;
}


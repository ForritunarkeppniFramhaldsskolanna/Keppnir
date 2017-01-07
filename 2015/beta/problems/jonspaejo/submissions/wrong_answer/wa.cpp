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

vector<char> res;
string s;
void bt(int at) {
    if (at == size(s)) {
        for (int i = 0; i < size(res); i++) {
            cout << res[i];
        }
        cout << endl;
    } else if (s[at] == '?') {

        for (int d = 0; d < 10; d++) {
            res.push_back(d + '0');
            bt(at + 1);
            res.pop_back();
        }

    } else {
        res.push_back(s[at]);
        bt(at + 1);
        res.pop_back();
    }
}

int main()
{
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < size(s); i++) {
        if (s[i] == '?')
            cnt++;
    }

    if (cnt >= 5) {
        cout << "Fjoldi: ";
        ll res = 1;
        for (int i = 0; i < cnt; i++)
            res *= 10;

        cout << res << endl;
        return 0;
    }

    bt(0);

    return 0;
}


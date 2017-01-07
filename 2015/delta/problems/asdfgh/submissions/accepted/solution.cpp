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

string same[] = {
    "pyfgcrl",
    "aoeeuidhtns",
    "qjkxbmwvz"
};

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < 3; i++) {
        bool all = true;
        for (int j = 0; j < size(s); j++) {
            bool found = false;
            for (int k = 0; k < size(same[i]); k++) {
                if (same[i][k] == s[j]) {
                    found = true;
                }
            }

            if (!found) {
                all = false;
            }
        }

        if (all) {
            cout << "Jebb" << endl;
            return 0;
        }
    }

    cout << "Neibb" << endl;

    return 0;
}


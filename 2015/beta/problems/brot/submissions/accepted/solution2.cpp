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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    double x;
    cin >> x;

    int a = round(x * 100000),
       b = 100000;

    int g = gcd(a, b);
    a /= g;
    b /= g;

    cout << a << "/" << b << endl;

    return 0;
}


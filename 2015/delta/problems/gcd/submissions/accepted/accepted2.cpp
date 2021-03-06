#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define foreach(u, o) \
    for (typeof((o).begin()) u = (o).begin(); u != (o).end(); ++u)
const int INF = 2147483647;
const double EPS = 1e-9;
const double pi = acos(-1);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T mod(T a, T b) { return (a % b + b) % b; }
template <class T> int size(const T &x) { return x.size(); }

int gcd(int a, int b){
    int g = 1;
    for(int i = 2; i <= min(a, b); ++i){
        if(a % i == 0 && b % i == 0){
            g = i;
        }
    }
    return g;
}

int main(){
    int N;
    cin >> N;
    int g, m;
    cin >> g;
    for(int i = 1; i < N; ++i){
        cin >> m;
        g = gcd(g, m);
    }
    cout << g << endl;
}

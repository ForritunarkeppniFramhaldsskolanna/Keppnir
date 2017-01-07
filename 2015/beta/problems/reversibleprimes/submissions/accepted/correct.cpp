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

const int MX = 1000000;

char num[10];

int reverse(int n){
    sprintf(num, "%d", n);
    int i = 0, j = strlen(num)-1;
    //printf("%s\n", num);
    while(i < j){
        swap(num[i], num[j]);
        i++; j--;
    }
    return atoi(num);
}

int main() {
    int N;
    scanf("%d", &N);
    bool p[MX+1];
    memset(p, 0, sizeof p);
    for(int i = 2; i*i <= MX; i = (i == 2) ? 3 : i + 2){
        if(!p[i]){
            for(int j = i + i; j <= MX; j += i){
                p[j] = true;
            }
        }
    }

    for(int i = 2; i <= N; i = i == 2 ? 3 : i + 2){
        if(!p[i] && !p[reverse(i)]){
            printf("%d\n", i);
        }
    }
}

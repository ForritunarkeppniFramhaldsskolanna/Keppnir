#include <bits/stdc++.h>
using namespace std;
//template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

int main() {
    int a, b, c, d;
    scanf("%d:%d\n%d:%d\n", &a, &b, &c, &d);
    printf("%d\n", (1440 + (c*60+d)-(a*60+b))%1440);
    return 0;
}


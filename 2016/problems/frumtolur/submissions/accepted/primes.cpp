#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
template <class T> int size(const T &x) { return x.size(); }
const int INF = 2147483647;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

bool is_prime(int n) {
    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    if (n < 25) return true;
    for (int i = 5; i*i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true; }

int main() {
    for (int i = 2, j = 0; j < 100; i++) {
        if (is_prime(i)) {
            printf("%d\n", i);
            j++;
        }
    }

    return 0;
}


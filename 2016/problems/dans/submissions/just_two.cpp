/*
 * Expected number of points: 10+25 = 35
*/

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

int main() {
    int n, k;
    cin >> n >> k;

    int arr[2];
    cin >> arr[0];
    cin >> arr[1];

    if (arr[0] == 1) {
        cout << "1 2" << endl;
    } else if (k % 2 == 0) {
        cout << "1 2" << endl;
    } else {
        cout << "2 1" << endl;
    }

    return 0;
}


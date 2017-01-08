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
    int n;
    cin >> n;

    int a = 0,
        b = 0;
    rep(i,0,n) {
        string name, city;
        cin >> name >> city;
        if (city == "Akureyri") {
            a++;
        } else if (city == "Reykjavik") {
            b++;
        } else {
            assert(false);
        }
    }
    if (a != 0) {
        cout << "Akureyri " << a << endl;
    }
    if (b != 0) {
        cout << "Reykjavik " << b << endl;
    }
    return 0;
}


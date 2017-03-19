#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = 2147483647;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int a = 0,
        b = 0,
        left = 5,
        acur = 0,
        bcur = 0;
    rep(i,0,size(s)) {
        if (s[i] == 'A') acur++;
        else bcur++;
        left--;
        if (acur > bcur + left) {
            a++;
            acur = bcur = 0;
            left = 5;
        } else if (bcur > acur + left) {
            b++;
            acur = bcur = 0;
            left = 5;
        }
        if (a == n) {
            cout << "Hannes" << endl;
            break;
        } else if (b == n) {
            cout << "Arnar" << endl;
            break;
        }
    }

    return 0;
}


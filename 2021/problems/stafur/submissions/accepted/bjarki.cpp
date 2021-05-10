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
    char c;
    cin >> c;

    switch (c) {
        case 'A':
        case 'E':
        case 'O':
        case 'I':
        case 'U':
            cout << "Jebb" << endl;
            break;
        case 'Y':
            cout << "Kannski" << endl;
            break;
        default:
            cout << "Neibb" << endl;
    }

    return 0;
}


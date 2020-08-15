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

char arr[1000000];

int main() {
    int n, k;
    cin >> n >> k;

    int cnt = 0;
    rep(i,0,n) {
        cin >> arr[i];
        cnt += arr[i] == 'o';
    }
    rep(i,0,n) {
        char tmp;
        cin >> tmp;
    }

    rep(i,0,k) {
        char op;
        cin >> op;
        if (op == 'U') {
            int x, y;
            cin >> x >> y;
            x--, y--;
            if (arr[y] == 'o') {
                arr[y] = '.';
                cnt--;
            } else {
                arr[y] = 'o';
                cnt++;
            }
        } else {
            if (cnt == 0) {
                cout << "Jebb" << endl;
            } else {
                cout << "Neibb" << endl;
            }
        }
    }

    return 0;
}


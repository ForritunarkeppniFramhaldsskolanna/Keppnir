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

int main(int argc, char *argv[]) {
    srand(atoi(argv[2]));
    int n = atoi(argv[1]);

    set<string> S;

    cout << n << endl;
    rep(i,0,n) {
        while (true) {
            int l = rand() % 20 + 1;
            stringstream ss;
            rep(j,0,l) {
                ss << static_cast<char>(rand() % 4 + 'a');
            }
            string s = ss.str();
            if (S.find(s) == S.end()) {
                cout << s << endl;
                S.insert(s);
                break;
            }
        }
    }

    return 0;
}


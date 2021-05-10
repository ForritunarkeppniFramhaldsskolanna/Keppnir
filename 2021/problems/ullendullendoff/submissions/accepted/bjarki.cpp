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


vector<string> parts = {
"Úllen",
"dúllen",
"doff",
"kikke",
"lane",
"koff",
"koffe",
"lane",
"bikke",
"bane",
"úllen",
"dúllen",
"doff",
};

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    rep(i,0,n) {
        cin >> arr[i];
    }

    int l = 0,
        r = 0;
    while (l < (int)parts.size()-1) {
        l++;
        r = (r+1)%n;
    }
    cout << arr[r] << endl;

    return 0;
}


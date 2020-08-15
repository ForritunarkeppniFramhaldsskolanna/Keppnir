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

int n, m;
int preorder[1000000],
    pat = 0,
    inorder[1000000];
vi loc[100100],
   children[100100];

int parse(int l, int r) {
    int root = preorder[pat++];

    if (l == r) {
        // leaf
    } else {
        iter(it,loc[root]) {
            int child = parse(l, *it-1);
            children[root].push_back(child);
            l = *it+1;
        }
        int child = parse(l, r);
        children[root].push_back(child);
    }

    return root;
}

int main() {
    cin >> n >> m;

    rep(i,0,n) {
        cin >> preorder[i];
    }
    rep(i,0,m) {
        cin >> inorder[i];
        loc[inorder[i]].push_back(i);
    }

    parse(0, m-1);

    rep(i,1,n+1) {
        cout << i << ":";
        iter(it,children[i]) {
            cout << " " << *it;
        }
        cout << endl;
    }

    return 0;
}


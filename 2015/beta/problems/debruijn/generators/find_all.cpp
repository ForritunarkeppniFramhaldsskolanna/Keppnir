#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T &x) { return x.size(); }

// assert or gtfo

ll mypow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

int a, k;
set<ll> found;
vector<int> seq;
int cnt, tot = 0;
void bt(int at, int n) {

    vector<ll> added;

    if (at >= k) {
        ll cur = 0;
        for (int i = 0; i < k; i++) {
            cur = cur * a + seq[at - k + i];
        }

        if (found.find(cur) != found.end()) {
            return;
        }

        added.push_back(cur);
        found.insert(cur);
    }

    if (at == n) {

        // for (int i = 0; i < n; i++) {
        //     cout << seq[i] << " ";
        // }
        // cout << endl;

        bool ok = true;

        for (int i = n - k + 1; i < n; i++) {

            ll tmp = 0;
            for (int j = 0; j < k; j++) {
                tmp = tmp * a + seq[(i + j) % n];
            }

            // for (int j = 0; j < k; j++) {
            //     cout << seq[(i+j) % n];
            // }
            // cout << endl;

            if (found.find(tmp) != found.end()) {
                ok = false;
                break;
            } else {
                added.push_back(tmp);
                found.insert(tmp);
            }
        }

        if (ok) {
            tot++;
            for (int i = 0; i < n; i++) {
                cout << seq[i] << " ";
            }
            cout << endl;
            exit(0);
        }

    } else {
        vector<int> chars;
        for (int i = 0; i < a; i++)
            chars.push_back(i);

        random_shuffle(chars.begin(), chars.end());

        for (int i = 0; i < a; i++) {
            seq.push_back(chars[i]);
            bt(at + 1, n);
            seq.pop_back();
        }
    }

    for (int i = 0; i < size(added); i++) {
        found.erase(added[i]);
    }
}

int main() {

    // srand(time(NULL));
    srand( (unsigned) time(NULL) * getpid() );

    cin >> a >> k;
    cnt = mypow(a, k);

    bt(0, cnt);
    cout << tot << endl;
    cout << tot / cnt << endl;

    return 0;
}


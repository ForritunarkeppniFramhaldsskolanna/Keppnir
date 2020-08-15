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
vi above;
vector<pair<int,string> > arr;
int mem[10100][2];
int decic[10100][2];
char ans[10100];

bool dp(int at, int abovedir) {
    if (at == m) {
        return true;
    }
    if (mem[at][abovedir] != -1) {
        return mem[at][abovedir];
    }

    int a = above[at];
    for (int curdir = 0; curdir < 2; curdir++) {
        bool ok = true;
        if (a != -1) {
            for (int i = 0; i < arr[at].second.size(); i++) {
                char p = curdir == 0 ? arr[at].second[i] : arr[at].second[(int)arr[at].second.size() - 1 - i];
                int j = arr[at].first + i - arr[a].first;
                if (abovedir == 1) {
                    j = (int)arr[a].second.size()-1-j;
                }
                if (0 <= j && j < arr[a].second.size()) {
                    ok = ok && p == arr[a].second[j];
                }
            }
        }
        if (ok) {
            int nabovedir = abovedir;
            if (at + 1 < m && above[at+1] == at) {
                nabovedir = curdir;
            }
            if (dp(at+1, nabovedir)) {
                decic[at][abovedir] = curdir;
                return mem[at][abovedir] = 1;
            }
        }
    }
    return mem[at][abovedir] = 0;
}

void rec(int at, int abovedir) {
    if (at == m) {
        return;
    }

    int a = above[at];
    int curdir = decic[at][abovedir];

    for (int i = 0; i < arr[at].second.size(); i++) {
        char p = curdir == 0 ? arr[at].second[i] : arr[at].second[(int)arr[at].second.size() - 1 - i];
        ans[arr[at].first + i] = p;
    }

    int nabovedir = abovedir;
    if (at + 1 < m && above[at+1] == at) {
        nabovedir = curdir;
    }
    rec(at+1, nabovedir);
}

char alpha[4] = {'G', 'T', 'A', 'C'};

int main() {
    memset(mem,-1,sizeof(mem));
    memset(ans,0,sizeof(ans));

    srand(time(NULL));

    cin >> n >> m;

    rep(i,0,m) {
        int start;
        string s;
        cin >> start >> s;
        start--;
        arr.push_back(make_pair(start, s));
    }

    sort(arr.begin(), arr.end());
    above = vi(m, -1);

    int best = -1;
    rep(i,0,m) {
        above[i] = best;
        if (best == -1 || arr[best].first + arr[best].second.size() < arr[i].first + arr[i].second.size()) {
            best = i;
        }
    }

    if (!dp(0, 0)) {
        cout << "Villa" << endl;
        return 0;
    }
    rec(0,0);

    rep(i,0,n-1) {
        if (ans[i] == 0) {
            cout << alpha[rand() % 4];
        } else {
            cout << ans[i];
        }
    }
    cout << endl;

    return 0;
}


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

vi* adj;
bool* done;
int* owner;
int alternating_path(int left) {
    if (done[left]) return 0;
    done[left] = true;
    rep(i,0,size(adj[left])) {
        int right = adj[left][i];
        if (owner[right] == -1 || alternating_path(owner[right])) {
            owner[right] = left; return 1;
        } }
    return 0; }

int main() {
    int n,m;
    scanf("%d", &n);
    m = n;
    vii arr(n);
    rep(i,0,n) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    vi sizes(m);
    rep(i,0,m) {
        scanf("%d", &sizes[i]);
    }

    adj = new vi[n];
    done = new bool[n];
    owner = new int[m];
    memset(owner,-1,m*sizeof(int));
    int ecnt = 0;
    rep(i,0,n) {
        rep(j,0,m) {
            if (arr[i].first <= sizes[j] && sizes[j] <= arr[i].second) {
                assert(ecnt++ <= 100000000);
                adj[i].push_back(j);
            }
        }
    }

    int cnt = 0;
    rep(i,0,n) {
        memset(done,0,n*sizeof(bool));
        cnt += alternating_path(i);
    }

    if (cnt == n) {
        printf("Jebb\n");
    } else {
        printf("Neibb\n");
    }

    return 0;
}


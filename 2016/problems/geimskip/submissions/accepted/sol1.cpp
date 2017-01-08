#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31); // 2147483647

const double EPS = 1e-9;
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T mod(T a, T b) { return (a % b + b) % b; }

ll distsquared(vector<ll> &P0, vector<ll> &P1){
    return (P0[0] - P1[0]) * (P0[0] - P1[0])
         + (P0[1] - P1[1]) * (P0[1] - P1[1])
         + (P0[2] - P1[2]) * (P0[2] - P1[2]);
}


int main(){
    int N, M;
    cin >> N;
    vector<vector<ll> > fleet(N, vector<ll>(4));
    vi explodes(N);

    rep(i,0,N){
        cin >> fleet[i][0] >> fleet[i][1] >> fleet[i][2] >> fleet[i][3];
    }

    cin >> M;
    vector<vector<ll> > bombs(M, vector<ll>(4));

    rep(i,0,M){
        cin >> bombs[i][0] >> bombs[i][1] >> bombs[i][2] >> bombs[i][3];
    }

    rep(i,0,M){
        rep(j,0,N){
            if(distsquared(bombs[i], fleet[j]) <= (bombs[i][3] + fleet[j][3])*(bombs[i][3] + fleet[j][3])){
                explodes[j] = 1;
            }
        }
    }

    queue<int> Q;

    rep(i,0,N){
        if(explodes[i]){
            Q.push(i);
        }
    }

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        rep(i,0,N){
            if(i == cur) continue;
            if(explodes[i]) continue;

            if(distsquared(fleet[cur], fleet[i]) <= (2*fleet[cur][3] + fleet[i][3])*(2*fleet[cur][3] + fleet[i][3])){
                explodes[i] = true;
                Q.push(i);
            }
        }
    }
    int cnt = N;
    rep(i,0,N){
        if(explodes[i]) {
            cnt--;
        }
    }
    cout << cnt << endl;
}

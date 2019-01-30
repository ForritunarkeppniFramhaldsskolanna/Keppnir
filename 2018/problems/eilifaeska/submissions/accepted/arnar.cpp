#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;

int main() {
    cin.sync_with_stdio(false);
	int n;
	cin >> n;
	vi A(n);
	rep(i,0,n) cin >> A[i];
	if(n == 1)
    {
        cout << 0 << endl;
    }
    else if(n == 2)
    {
        if(A[0] < A[1]) cout << 1 << endl << "2 1" << endl;
        else cout << 1 << endl << "1 2" << endl;
    }
    else if(n == 3)
    {
        int mxi = 0, mni = 0, midi = 0;
        rep(i,0,n)
        {
            if(A[i] > A[mxi]) mxi = i;
        }
        rep(i,0,n)
        {
            if(mni == mxi || A[i] < A[mni]) mni = i;
        }
        rep(i,0,n)
        {
            if(i != mxi && i != mni) midi = i;
        }
        if(2*A[midi] == A[mxi] + A[mni])
        {
            cout << 1 << endl;
            cout << mxi+1 << " " << mni+1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    else if(n == 4)
    {
        vii AS(n);
        rep(i,0,n) AS[i] = ii(A[i], i+1);
        sort(AS.begin(), AS.end());
        if(AS[0].first == AS[1].first && AS[2].first == AS[3].first)
        {
            cout << 2 << endl;
            cout << AS[3].second << " " << AS[1].second << endl;
            cout << AS[2].second << " " << AS[0].second << endl;
        }
        else
        {
            cout << 4 << endl;
            cout << AS[3].second << " " << AS[2].second << endl;
            cout << AS[1].second << " " << AS[0].second << endl;
            cout << AS[3].second << " " << AS[1].second << endl;
            cout << AS[2].second << " " << AS[0].second << endl;
        }
    }
    return 0;
}



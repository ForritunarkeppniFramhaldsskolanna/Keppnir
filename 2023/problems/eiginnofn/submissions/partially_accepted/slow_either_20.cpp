#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
#define fs first
#define sc second
#define pb push_back
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

bool starts_with(const string& s, const string& t)
{
    return s.rfind(t, 0) == 0;
}


int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore();
    vector<string> home;
    bool one = true;
    rep(i,0,n)
    {
        string s;
        getline(cin, s);
        home.push_back(s);
        if (s.find(' ') != string::npos) one = false;
    }

    int m;
    cin >> m;
    rep(i,0,m)
    {
        string s;
        cin >> s;
        if (!one) s.push_back(' ');
        auto it = find_if(home.begin(), home.end(), [s](const string& val){ return starts_with(val, s); });
        if (one) it = find(home.begin(), home.end(), s);
        if (it == home.end())
        {
            cout << "Neibb";
        }
        else 
        {
            if (one) cout << "Jebb";
            else cout << "Neibb en " << *it << " er heima";
        }
        cout << endl;
    }

    return 0;
}

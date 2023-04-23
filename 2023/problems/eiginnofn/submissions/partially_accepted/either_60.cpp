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

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore();
    map<string, string> home;
    bool one = true;
    rep(i,0,n)
    {
        string s;
        getline(cin, s);
        auto space_index = s.find(' ');
        if (space_index == string::npos)
        {
            home[s] = "";
        }
        else
        {
            home[s.substr(0, space_index)] = s.substr(space_index+1);
            one = false;
        }
    }

    int m;
    cin >> m;
    rep(i,0,m)
    {
        string s;
        cin >> s;
        if (home.count(s))
        {
            if (one)
            {
                cout << "Jebb";
            }
            else 
            {
                cout << "Neibb en " << s << " " << home[s] << " er heima";
            }
        }
        else 
        {
            cout << "Neibb";
        }
        cout << endl;
    }

    return 0;
}

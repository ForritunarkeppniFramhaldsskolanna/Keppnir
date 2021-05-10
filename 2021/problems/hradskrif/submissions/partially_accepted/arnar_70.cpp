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
    vector<string> text(n);
    set<string> unq;

    rep(i,0,n)
    {
        cin >> text[i];
        unq.insert(text[i]);
    }
    map<string,int> dict;
    iter(it, unq)
    {
        string prefix = "";
        dict[prefix]++;
        rep(j,0,(int)(it->size()))
        {
            prefix += (*it)[j];
            dict[prefix]++;
        }
    }

    int sm = 0;
    rep(i,0,n)
    {
        int reduced = -1;
        string prefix = "";
        rep(j,0,(int)text[i].size()+1)
        {
            int cnt = dict[prefix];
            if(cnt == 1)
            {
                reduced = j;
                break;
            }
            if(j < (int)text[i].size()) prefix += text[i][j];
        }
        int full = text[i].size();
        if(reduced == -1) reduced = full; // word not in dictionary, write it out fully
        else if(reduced < full) reduced++; // write proper prefix and press tab
        // else just write the word fully
        sm += max(0, full - reduced);
    }

    cout << sm << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
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
    string s = "";
    string line;
    cin >> line;
    if(size(line) > 1000) return 0;
    int pos = 0;
    rep(i,0,size(line))
    {
        if(line[i] == 'L')
        {
            pos--;
        }
        else if(line[i] == 'R')
        {
            pos++;
        }
        else if(line[i] == 'B')
        {
            s = s.substr(0, pos-1) + (pos < size(s) ? s.substr(pos) : "");
            pos--;
        }
        else
        {
            s = s.substr(0, pos) + line[i] + s.substr(pos);
            pos++;
        }
    }
    cout << s << endl;
    return 0;
}

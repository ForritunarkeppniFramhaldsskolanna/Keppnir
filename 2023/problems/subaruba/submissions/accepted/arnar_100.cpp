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
    
    const string KEY{ "ub" };

    string mode;
    cin >> mode;
    int n;
    cin >> n;
    string token;
    array<char, 6> vowels{'a', 'e', 'i', 'o', 'u', 'y'};
    while (cin >> token)
    {
        if (mode == "D")
        {
            for(size_t i = 0; i < token.size(); i++)
            {
                if(find(vowels.begin(), vowels.end(), std::tolower(token[i])) != vowels.end()) {
                    cout << KEY;
                }
                cout << token[i];
            }
        }
        else
        {
            for(size_t i = 0; i < token.size(); i++)
            {
                bool match = true;
                for(size_t j = 0; j < KEY.size(); j++)
                {
                    match &= std::tolower(token[i+j]) == KEY[j];
                }
                if(match) i += KEY.size();
                cout << token[i];
            }
        }
        cout << " ";
    }
    cout << endl;

    return 0;
}

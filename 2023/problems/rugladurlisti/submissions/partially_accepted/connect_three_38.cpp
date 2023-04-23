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

vector<int> send_query(const vector<int>& query)
{
    cout << "? " << query.size();
    for(auto x : query)
    {
        cout << " " << x+1;
    }
    cout << endl;

    vector<int> result(query.size());
    for(auto& x : result)
    {
        cin >> x;
        x--;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    
    vector<int> indices(n);
    const int BLOCK_SIZE = 3;

    for(int block = 0; block*(BLOCK_SIZE-1) < n; block++)
    {
        vector<int> query;
        int start_index = block*(BLOCK_SIZE-1);
        for(int i = start_index; i < min(start_index + BLOCK_SIZE, n); i++)
        {
            query.push_back(i);
        }

        for (auto x : send_query(query))
        {
            indices[x] = max(indices[x], start_index);
        }
    }

    for(int index = 1; index < BLOCK_SIZE - 1; index++)
    {
        vector<int> query;
        for(int i = index; i < n; i += BLOCK_SIZE - 1)
        {
            query.push_back(i);
        }
        
        for (auto x : send_query(query))
        {
            indices[x] += index;
        }
    }

    vector<int> answer(n);
    for(int i = 0; i < n; i++)
    {
        answer[indices[i]] = i;
    }

    cout << "!";
    for(auto x : answer)
    {
        cout << " " << x+1;
    }
    cout << endl;

    return 0;
}

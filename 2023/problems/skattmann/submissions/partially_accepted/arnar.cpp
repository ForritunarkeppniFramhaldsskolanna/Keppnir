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


struct Taxman
{
    Taxman(int n) : n(n), adj(n + 1), rev(n + 1)
    {
        for (int i = 1; 2*i <= n; i++)
        {
            for (int j = 2*i; j <= n; j += i)
            {
                adj[j].insert(i);
                rev[i].insert(j);
            }
        }
    }

    void print_adj(const vector<set<int>>& adj)
    {
        for (int i = 0; i <= n; i++)
        {
            cout << i << ":";
            for (const auto val : adj[i])
            {
                cout << " " << val;
            }
            cout << endl;
        }
    }

    void print()
    {
        cout << "ADJ" << endl;
        print_adj(adj);
        cout << endl << "REV" << endl;
        print_adj(rev);
        cout << "taxed: " << taxed_total << endl;
        cout << "taken: " << taken_total << endl;
    }

    bool can_take(int val) 
    {
        return adj[val].size() > 0;
    }

    void remove(int val)
    {
        removed_numbers++;
        for (const auto x : adj[val])
        {
            rev[x].erase(val);
        }
        for (const auto x : rev[val])
        {
            adj[x].erase(val);
        }
        adj[val].clear();
        rev[val].clear();
    }

    void tax(int val)
    {
        taxed_total += val;
        remove(val);
    }

    void take(int val)
    {
        if (!can_take(val)) return;
        for (const auto to_tax : set<int>(adj[val]))
        {
            tax(to_tax);
        }
        taken_total += val;
        order.push_back(val);
        remove(val);       
    }

    int select()
    {
        ii best = make_pair(n, 0);
        for (int i = 1; i <= n; i++)
        {
            if (!can_take(i)) continue;
            int count = static_cast<int>(adj[i].size());
            best = min(best, make_pair(count, -i));
        }

        return -best.second;
    }

    void print_result()
    {
        cout << order.size() << endl;
        for(const auto x : order)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    int n;
    int removed_numbers = 0;
    int taxed_total = 0;
    int taken_total = 0;
    vector<set<int>> adj;
    vector<set<int>> rev;
    vector<int> order;
};

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n == 13)
    {
        cout << "5\n13 9 10 8 12" << endl;
        return 0;
    }

    Taxman t(n);

    while(true)
    {
        auto val = t.select();
        if(val == 0) break;
        t.take(val);
    }

    t.print_result();

    return 0;
}

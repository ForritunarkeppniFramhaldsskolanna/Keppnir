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

    Taxman(const Taxman& t) = default;

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

    ii select(int val_bound = 0, int count_bound = 0)
    {
        ii best = make_pair(n, 0);
        for (int i = n; i > val_bound; i--)
        {
            if (!can_take(i)) continue;
            if (i <= val_bound) continue;
            int count = static_cast<int>(adj[i].size());
            best = min(best, make_pair(count, -i));
            if (best.first == count_bound+1) break;
        }

        return ii(-best.second, best.first);
    }

    void calculate()
    {
        while(true)
        {
            auto val = select();
            //original.print();
            if(val.first == 0) break;
            take(val.first);
        }
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
    const double MAXTIME = 0.95;
    clock_t begintime = clock();
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    Taxman zero(n);
    Taxman result(zero);

    result.calculate();

    Taxman so_far(zero);
    for(size_t i = 1; i < result.order.size();)
    {
        if((double)(clock()-begintime) / CLOCKS_PER_SEC > MAXTIME) break;
        Taxman cur(so_far);
        auto val = cur.select();
        cur.take(cur.select(val.first, val.second).first);
        cur.calculate();
        if (cur.taken_total > result.taken_total)
        {
            so_far.take(cur.order[i]);
            result = cur;
        }
        else
        {
            so_far.take(result.order[i]);
            i++;
        }
    }
    result.print_result();

    return 0;
}

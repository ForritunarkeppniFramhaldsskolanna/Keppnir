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

std::mt19937 gen;

// Random partition of n with max part = k
vector<ll> random_partition(ll n, ll k, ll bound=-1)
{
    long double x = exp(-pi/sqrt(6*n));
    bound = bound == -1 ? n : bound;
    vector<long double> Z(k+1);
    ll attempt_no = 0;
    while(true)
    {
        attempt_no++;
        Z.assign(k+1, 0);
        Z[k] = 1;
        long double y = 1.0;
        ll sm = 0;
        rep(i, 1, k+1)
        {
            y *= x;
            std::geometric_distribution<ll> d(1 - y);
            Z[i] += d(gen);
            sm += i * Z[i];
        }
        if (bound <= sm && sm <= n) break;
        if(attempt_no % 100 == 0) bound--;
    }

    vector<ll> partition;
    rep(i,1,k+2)
    {
        rep(j,0,Z[i]) partition.push_back(i);
    }
    
    return partition;
}

vector<ll> conjugate(const vector<ll>& partition)
{
    cout << "CONJUGATE TIME" << endl;
    vector<ll> conj;
    ll x = 0;
    size_t i = 0;
    while(i < partition.size())
    {
        while(x < partition[i])
        {
            x++;
            conj.push_back(static_cast<ll>(partition.size()) - i);
        }
        i++;
    }
    return conj;
}

vector<ll> random_partition_exact_parts(ll n, ll k, ll bound=-1)
{
    return conjugate(random_partition(n, k, bound));
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    
    if (argc < 4)
    {
        return 1;
    }
    ll n = atoi(argv[1]);
    ll k = atoi(argv[2]);
    ll seed = atoi(argv[3]);
    gen.seed(seed);
    

    for(const auto& val : random_partition_exact_parts(n, k, static_cast<ll>(n)))
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

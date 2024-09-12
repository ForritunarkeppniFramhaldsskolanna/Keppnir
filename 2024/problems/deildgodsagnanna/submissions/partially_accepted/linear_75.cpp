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


template <class T>
T egcd(T a, T b, T& x, T& y) {
  if (b == 0) { x = 1; y = 0; return a; }
  T d = egcd(b, a % b, x, y);
  x -= a / b * y; swap(x, y); return d; }
template <class T>
T mod_inv(T a, T m) {
  T x, y, d = egcd(a, m, x, y);
  return d == 1 ? smod(x,m) : -1; }

constexpr ll MOD{ 1'000'000'007LL };

ll factorial(ll n) {
    ll res = 1LL;
    while (n--) res = res * (n+1) % MOD;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;

    cout << factorial(n) * mod_inv(factorial(n-20), MOD) % MOD * mod_inv(8LL, MOD) % MOD << endl;

    return 0;
}

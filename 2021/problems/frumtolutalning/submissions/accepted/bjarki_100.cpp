#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

__int128 smod(__int128 a, __int128 b) {
    return (a % b + b) % b;
}

template <class T>
T mod_pow(T b, T e, T m) {
  T res = T(1);
  while (e) {
    if (e & T(1)) res = smod(res * b, m);
    b = smod(b * b, m), e >>= T(1); }
  return res; }

bool is_probable_prime(__int128 n, int k) {
  if (~n & 1) return n == 2;
  if (n <= 3) return n == 3;
  int s = 0; __int128 d = n - 1;
  while (~d & 1) d >>= 1, s++;
  while (k--) {
    __int128 a = (n - 3) * rand() / RAND_MAX + 2;
    __int128 x = mod_pow(a, d, n);
    if (x == 1 || x == n - 1) continue;
    bool ok = false;
    rep(i,0,s-1) {
      x = (x * x) % n;
      if (x == 1) return false;
      if (x == n - 1) { ok = true; break; }
    }
    if (!ok) return false;
  } return true; }

vi prime_sieve(int n) {
  int mx = (n - 3) >> 1, sq, v, i = -1;
  vi primes;
  bool* prime = new bool[mx + 1];
  memset(prime, 1, mx + 1);
  if (n >= 2) primes.push_back(2);
  while (++i <= mx) if (prime[i]) {
    primes.push_back(v = (i << 1) + 3);
    if ((sq = i * ((i << 1) + 6) + 3) > mx) break;
    for (int j = sq; j <= mx; j += v) prime[j] = false; }
  while (++i <= mx)
    if (prime[i]) primes.push_back((i << 1) + 3);
  delete[] prime; // can be used for O(1) lookup
  return primes; }

unordered_map<ll,ll> primepi(ll n) {
#define f(n) (1)
#define F(n) (n)
  ll st = 1, *dp[3], k = 0;
  while (st*st < n) st++;
  vi ps = prime_sieve(st);
  ps.push_back(st+1);
  rep(i,0,3) dp[i] = new ll[2*st];
  ll *pre = new ll[(int)ps.size()-1];
  rep(i,0,(int)ps.size()-1)
    pre[i] = f(ps[i]) + (i == 0 ? f(1) : pre[i-1]);
#define L(i) ((i)<st?(i)+1:n/(2*st-(i)))
#define I(l) ((l)<st?(l)-1:2*st-n/(l))
  rep(i,0,2*st) {
    ll cur = L(i);
    while ((ll)ps[k]*ps[k] <= cur) k++;
    dp[2][i] = k, dp[1][i] = F(L(i)), dp[0][i] = 0; }
  for (int j = 0, start = 0; start < 2*st; j++) {
    rep(i,start,2*st) {
      if (j >= dp[2][i]) { start++; continue; }
      ll s = j == 0 ? f(1) : pre[j-1];
      int l = I(L(i)/ps[j]);
      dp[j&1][i] = dp[~j&1][i]
        - f(ps[j]) * (dp[~min(j,(int)dp[2][l])&1][l] - s);
    } }
  unordered_map<ll,ll> res;
  rep(i,0,2*st) res[L(i)] = dp[~dp[2][i]&1][i]-f(1);
  delete[] pre; rep(i,0,3) delete[] dp[i];
  return res; }

int main() {
    ll a, b;
    cin >> a >> b;

    ll cnt = 0;

    if (b-a <= 100000) {
        for (ll i = a; i <= b; i++) {
            // XXX: Make sure this is large enough!
            if (is_probable_prime(i, 20)) {
                cnt++;
            }
        }
    } else if (b <= 1000000000000LL) {
        unordered_map<ll,ll> acnt = primepi(a-1);
        unordered_map<ll,ll> bcnt = primepi(b);
        cnt = bcnt[b] - acnt[a-1] - (a==1);
    } else {
        ll st = 1;
        while (st*st <= b) st++;

        bool *prime = new bool[st+1];
        prime[1] = false;
        for (ll i = 1; i <= st; i++) prime[i] = true;
        for (ll i = 2; i <= st; i++) {
            if (prime[i]) {
                for (ll j = i+i; j <= st; j += i) {
                    prime[j] = false;
                }
            }
        }

        vector<ll> primes;
        for (ll i = 2; i <= st; i++) {
            if (prime[i]) {
                primes.push_back(i);
            }
        }

        delete[] prime;
        prime = new bool[b-a+1];
        for (ll i = a; i <= b; i++) prime[i-a] = true;

        iter(it,primes) {
            for (ll i = (a+*it-1)/(*it)*(*it); i <= b; i += *it) {
                if (i != *it) {
                    prime[i-a] = false;
                }
            }
        }

        for (ll i = a; i <= b; i++) {
            if (prime[i-a] && i != 1) {
                cnt++;
            }
        }

        delete[] prime;
    }

    cout << cnt << endl;

    return 0;
}


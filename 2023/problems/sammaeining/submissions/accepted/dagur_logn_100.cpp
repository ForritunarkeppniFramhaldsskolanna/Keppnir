#pragma GCC optimize("Ofast","unroll-loops")
#pragma GCC target("avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
#define riter(it,c) for (__typeof((c).rbegin()) \
  it = (c).rbegin(); it != (c).rend(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
#define pb push_back
#define fs first
#define sc second
const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
	return (a % b + b) % b; }

ll modpow(ll base, ll expo, ll m) {
	ll res = 1;
	while (expo != 0) {
		if (expo & 1) {
			res *= base;
			res %= m;
		}
		base *= base;
		base %= m;
		expo >>= 1;
	}
	return res;
}

int main() {
	const ll m = 1'000'000'007;
	ll n;
	cin >> n;
	/* n = 69; */
	if (n <= 3) {
		cout << 0 << '\n';
		return 0;
	}
	if (n == 4) {
		cout << 2 << '\n';
		return 0;
	}
	ll nFloor = n / 10;
	/* printf("nFloor: %lld\n", nFloor); */
	ll delta = (modpow(4, nFloor, m) * 500000004) % m;
	/* printf("delta: %lld\n", delta); */
	ll guess = (modpow(2, nFloor * 10, m) + 4 * modpow(2, nFloor * 2, m)) % m;
	/* printf("g0: %lld\n", modpow(2, nFloor * 10, m)); */
	/* printf("g1: %lld\n", guess); */
	guess *= 700000005;
	guess %= m;
	/* printf("guess: %lld\n", guess); */
	ll arr[10];
	ll arr2[10];
	rep(idx, 0, 10) {
		if (idx % 5 == 0) {
			arr[idx] = guess;
			arr2[idx] = guess;
		} else {
			arr[idx] = smod(guess - delta, m);
			arr2[idx] = smod(guess - delta, m);
		}
	}

	/* cout << '[' << arr[0] << ", " << arr[1] << ", " << arr[2] << ", " << arr[3] << ", " << arr[4] << ", " << arr[5] << ", " << arr[6] << ", " << arr[7] << ", " << arr[8] << ", " << arr[9] << "]\n"; */

	rep(x, 1, (n % 10) + 1) {
		rep(idx, 0, 10) {
			arr[(idx + x) % 10] += arr2[idx];
			arr[(idx + x) % 10] %= m;
		}
		rep(idx, 0, 10) {
			arr2[idx] = arr[idx];
		}
		/* cout << x << ' '; */
		/* cout << '[' << arr[0] << ", " << arr[1] << ", " << arr[2] << ", " << arr[3] << ", " << arr[4] << ", " << arr[5] << ", " << arr[6] << ", " << arr[7] << ", " << arr[8] << ", " << arr[9] << "]\n"; */
	}

	cout << arr[7] << '\n';

	return 0;
}

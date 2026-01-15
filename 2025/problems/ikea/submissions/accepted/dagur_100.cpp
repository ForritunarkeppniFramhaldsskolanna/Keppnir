#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
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
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
	return (a % b + b) % b; }

int main() {
    ll k, n;
    cin >> k >> n;
    vector<pair<ll, string>> names;
    rep(_, 0, n) {
        ll weight;
        string name;
        cin >> name >> weight;
        names.push_back({weight, name});
    }

    stable_sort(names.begin(), names.end(), [](pair<int, string> const &a, pair<int, string> const &b) {
        return a.first < b.first;
    });

    ll amt = n / k;
    if (n % k == 0) {
        ll total = 0;
        vector<string> chosen;
        rep(idx, 0, amt) {
            total += names[idx].first;
            chosen.push_back(names[idx].second);
        }
        cout << total << '\n';
        sort(chosen.begin(), chosen.end());
        rep(idx, 0, amt) {
            cout << chosen[idx] << '\n';
        }
        return 0;
    }

    ll badPersonSum = 0;
    rep(idx, 0, amt + 1) {
        badPersonSum += names[idx].first;
    }

    ll nextSum = 0;
    rep(idx, amt + 1, 2 * amt + 1) {
        nextSum += names[idx].first;
    }

    amt += badPersonSum < nextSum;

    ll total = 0;
    vector<string> chosen;
    rep(idx, 0, amt) {
        total += names[idx].first;
        chosen.push_back(names[idx].second);
    }
    cout << total << '\n';
    sort(chosen.begin(), chosen.end());
    rep(idx, 0, amt) {
        cout << chosen[idx] << '\n';
    }

	return 0;
}

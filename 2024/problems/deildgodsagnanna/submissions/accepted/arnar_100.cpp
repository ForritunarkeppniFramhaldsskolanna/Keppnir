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

template<typename T, T M>
class int_mod {
public:
    int_mod(T val) : val(smod(val, M)) { }
    int_mod<T, M> operator+(const int_mod<T, M> other) {
        return int_mod<T, M>{ val + other.val };
    }
    int_mod<T, M> operator-(const int_mod<T, M> other) {
        return int_mod<T, M>{ val - other.val };
    }
    int_mod<T, M> operator*(const int_mod<T, M> other) {
        return int_mod<T, M>{ val * other.val };
    }
    int_mod<T, M> operator/(const int_mod<T, M> other) {
        return int_mod<T, M>{ val * other.inverse().val };
    }
    int_mod<T, M> operator+=(const int_mod<T, M> other) {
        this->val = smod(val + other.val, M);
        return *this;
    }
    int_mod<T, M> operator-=(const int_mod<T, M> other) {
        this->val = smod(val - other.val, M);
        return *this;
    }
    int_mod<T, M> operator*=(const int_mod<T, M> other) {
        this->val = smod(val * other.val, M);
        return *this;
    }
    int_mod<T, M> operator/=(const int_mod<T, M> other) {
        this->val = smod(val * other.inverse().val, M);
        return *this;
    }
    int_mod<T, M> inverse() const {
        return int_mod<T, M>{ mod_inv(val, M) };
    }
    T value() const {
        return val;
    }
private:
    T val;
};

template<typename T, T M>
ostream& operator<<(ostream& outs, int_mod<T, M> x) {
    outs << x.value();
    return outs;
}

int main()
{
    ios_base::sync_with_stdio(false);

    ll n_input;
    cin >> n_input;

    int_mod<ll, 1'000'000'007> n{ n_input };
    
    int_mod<ll, 1'000'000'007> result{ 1 };

    // Ban phase 1:    
    // Blue ban 1
    result = result * n;
    n -= 1;

    // Red ban 1
    result = result * n;
    n -= 1;
    
    // Blue ban 2
    result = result * n;
    n -= 1;

    // Red ban 2
    result *= n;
    n -= 1;
    
    // Blue ban 3
    result *= n;
    n -= 1;

    // Red ban 3
    result *= n;
    n -= 1;
    
    // Pick phase 1:
    // Blue pick 1
    result *= n;
    n -= 1;

    // Red pick 1 & 2
    result *= n * (n-1) / 2;
    n -= 2;

    // Blue pick 2 & 3
    result *= n * (n-1) / 2;
    n -= 2;

    // Red pick 3
    result *= n;
    n -= 1;

    // Ban phase 2
    // Red ban 4
    result *= n;
    n -= 1;

    // Blue ban 4
    result *= n;
    n -= 1;

    // Red ban 5
    result *= n;
    n -= 1;

    // Blue ban 5
    result *= n;
    n -= 1;

    // Pick phase 2
    // Red pick 4
    result *= n;
    n -= 1;

    // Blue pick 4 & 5
    result *= n * (n-1) / 2;
    n -= 2;
    
    // Red pick 5
    result *= n;
    n -= 1;

    cout << result << endl;

    return 0;
}

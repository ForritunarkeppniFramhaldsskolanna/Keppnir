#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll shf = 100000;
const ll rat = 9144;

int main() {
    ll n; cin >> n;
    n *= rat;
    cout << (n / shf) << '.' << (n % shf) << '\n';
}

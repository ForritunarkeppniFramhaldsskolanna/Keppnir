#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, P;
	cin >> n >> P;

	vector<ll> a(n);
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	ll asum = 0;
	for(int i=0; i<n; i++) asum += a[i];
	ll asqsum = 0;
	for(int i=0; i<n; i++) asqsum += a[i]*a[i];

	ll res = asum * asum - asqsum;

	cout << (res + P - 1) / P << endl;
}

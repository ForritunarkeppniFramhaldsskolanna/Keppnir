#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll r;
	cin >> r;

	ll atx = 0;
	ll aty = r;
	ll ans = 0;
	while(atx <= r){
		while(aty*aty + atx*atx > r*r){
			aty--;
		}
		ans += aty;
		atx++;
	}

	ans *= 4;
	ans++;

	cout << ans << endl;
}



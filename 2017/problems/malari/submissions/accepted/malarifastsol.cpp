
#include <queue>
#include <iostream>

typedef long long ll;

using namespace std;

int main(){
	ll N,M;
	cin >> N >> M;

	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >, greater<pair<ll,ll> > > seg;

	for(ll i=0; i<M; i++){
		pair<ll,ll> in;
		cin >> in.first >> in.second;
		seg.push(in);
	}

	ll lo = seg.top().first;
	ll hi = seg.top().second;
	seg.pop();
	ll ans = 0;

	while(!seg.empty()){
		pair<ll,ll> next = seg.top();
		seg.pop();

		if(hi >= next.first){
			if(hi >= next.second){
				// do nothing
			}else{
				hi = next.second;
			}
		}else{
			ans += hi - lo + 1;
			lo = next.first;
			hi = next.second;
		}
	}

	ans += hi - lo + 1;

	cout << ans << endl;
	if(ans > N/2){
		cout << "The Mexicans took our jobs! Sad!" << endl;
	}else{
		cout << "The Mexicans are Lazy! Sad!" << endl;
	}
}


#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N,M;
	cin >> N >> M;

	vector<bool> arr(N);

	for(int i=0; i<M; i++){
		int l,r;
		cin >> l >> r;
		l--;
		r--;

		for(int j=l; j<=r; j++){
			arr[j] = true;
		}
	}

	int ans= 0;

	for(int i=0; i<N; i++){
		ans += arr[i];
	}

	cout << ans << endl;
	if(ans*2 > N){
		cout << "The Mexicans took our jobs! Sad!" << endl;
	}else{
		cout << "The Mexicans are Lazy! Sad!" << endl;
	}

	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int& a : v) cin >> a, --a;
	vector<vector<int>> res(N, vector<int>(N, -1));
	for (int a = 0; a < N; ++a) {
		int b = a;
		for (int i = 0; ; ++i) {
			if (res[a][b] != -1) break;
			res[a][b] = i;
			b = v[b];
		}
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		cout << res[a][b] << endl;
	}
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i], --v[i];
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int a, b;
		cin >> a >> b;
		int r = 0;
		--a, --b;
		while (r < N && a != b)
			a = v[a], ++r;
		cout << (r == N ? -1 : r) << endl;
	}
}

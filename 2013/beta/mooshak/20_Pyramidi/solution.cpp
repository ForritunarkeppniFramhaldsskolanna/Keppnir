#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
#include <cassert>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T x) { return x.size(); }

// assert or gtfo

int main()
{
	int ts;
	scanf("%d\n", &ts);

	for (int t = 0; t < ts; t++)
	{
		int n;
		scanf("%d\n", &n);

		int x = (static_cast<int>(sqrt(static_cast<double>(8 * n + 1))) + 1) / 2;

		if (x * (x + 1) / 2 > n)
		{
			x--;
		}
		else if ((x + 1) * (x + 2) / 2 < n)
		{
			x++;
		}

		printf("%d %d\n", x, n - x * (x + 1) / 2);
	}

	return 0;
}
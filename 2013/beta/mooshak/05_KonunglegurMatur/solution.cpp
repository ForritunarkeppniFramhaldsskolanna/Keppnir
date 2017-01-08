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
		int n, x1, y1, x2, y2;
		scanf("%d %d %d %d %d\n", &n, &x1, &y1, &x2, &y2);

		int dx = abs(x1 - x2),
			dy = abs(y1 - y2);

		if (dx + dy <= 1 || (dx == 1 && dy == 1) || (dx == 1 && dy == 2) || (dx == 2 && dy == 1))
		{
			printf("Same\n");
		}
		else
		{
			printf("Queen\n");
		}
	}

	return 0;
}
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
	srand(time(NULL));

	int ts = 100;
	printf("%d\n", ts);

	for (int t = 0; t < ts; t++)
	{
		int l = rand() % 10001,
			n = rand() % (min(l + 1, 1000) - 1) + 1;

		bool* used = new bool[l + 1];
		memset(used, 0, l + 1);

		printf("%d %d\n", l, n);

		while (n > 0)
		{
			int cur = rand() % (l + 1);
			if (!used[cur])
			{
				used[cur] = true;
				n--;

				printf("%d", cur);

				if (n > 0)
				{
					printf(" ");
				}
			}
		}

		printf("\n");

		delete[] used;
	}

	return 0;
}
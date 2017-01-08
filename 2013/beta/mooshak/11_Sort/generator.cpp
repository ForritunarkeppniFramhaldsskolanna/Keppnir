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

void print_list(vector<int> xs)
{
	for (int i = 0, cnt = size(xs); i < cnt; i++)
	{
		if (i != 0) printf(" ");
		printf("%d", xs[i]);
	}

	printf("\n");
}

int main()
{
	srand(time(NULL));
	int ts = 1000;
	printf("%d\n", ts);

	for (int t = 0; t < ts; t++)
	{
		int nr = rand() % 1000 + 1;
		int n = rand() % nr + 1;
		int x = rand() % 5;

		int range = rand() % 1000 + 1;

		if (x == 0)
		{
			vector<int> xs;
			for (int i = 0; i < n; i++) xs.push_back(rand() % range - range / 2);
			print_list(xs);
			sort(all(xs));
			print_list(xs);
		}
		else if (x == 1)
		{
			vector<int> xs, ys;
			for (int i = 0; i < n; i++) xs.push_back(rand() % range - range / 2);
			for (int i = 0; i < n; i++) ys.push_back(rand() % range - range / 2);

			print_list(xs);
			print_list(ys);
		}
		else if (x == 2)
		{
			vector<int> xs, ys;
			for (int i = 0; i < n; i++) xs.push_back(rand() % range - range / 2);
			for (int i = 0; i < n; i++) ys.push_back(rand() % range - range / 2);

			print_list(xs);
			sort(all(ys));
			print_list(ys);
		}
		else if (x == 3)
		{
			int m = rand() % nr + 1;

			vector<int> xs, ys;
			for (int i = 0; i < n; i++) xs.push_back(rand() % range - range / 2);
			for (int i = 0; i < m; i++) ys.push_back(rand() % range - range / 2);

			print_list(xs);
			print_list(ys);
		}
		else if (x == 4)
		{
			int m = rand() % nr + 1;
			
			vector<int> xs, ys;
			for (int i = 0; i < n; i++) xs.push_back(rand() % range - range / 2);
			for (int i = 0; i < m; i++) ys.push_back(rand() % range - range / 2);

			print_list(xs);
			sort(all(ys));
			print_list(ys);
		}
	}

	return 0;
}
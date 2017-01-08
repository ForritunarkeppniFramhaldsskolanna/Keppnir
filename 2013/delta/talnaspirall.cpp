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
#define tryset(arr, x, y, v) if (x >= 0 && y >= 0 && x < n && y < n) arr[x][y] = v

// assert or gtfo

int main()
{
	int n;
	printf("Stærð: ");
	scanf("%d", &n);

	if (n < 1 || n > 19 || n % 2 == 0)
	{
		printf("Ekki lögleg stærð!\n");
		return 0;
	}

	int** arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];

	int x = (n - 1) / 2,
		y = (n - 1) / 2,
		cur = 0;

	tryset(arr, x, y, cur++);

	for (int i = 3; i <= n; i += 2)
	{
		y++;
		for (int j = 0; j < i - 2; j++)
		{
			tryset(arr, x, y, cur++);
			x--;
		}

		tryset(arr, x, y, cur++);

		for (int j = 0; j < i - 1; j++)
		{
			y--;
			tryset(arr, x, y, cur++);
		}

		for (int j = 0; j < i - 1; j++)
		{
			x++;
			tryset(arr, x, y, cur++);
		}

		for (int j = 0; j < i - 1; j++)
		{
			y++;
			tryset(arr, x, y, cur++);
		}
	}

	printf("\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d", arr[i][j]);
		}

		printf("\n");
	}


	return 0;
}
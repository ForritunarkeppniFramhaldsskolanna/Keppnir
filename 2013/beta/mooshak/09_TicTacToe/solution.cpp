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

string* arr;
int n;

char line(int x, int y, int dx, int dy)
{
	char last = arr[x][y];
	x += dx;
	y += dy;
	bool ok = true;

	while (ok && x >= 0 && y >= 0 && x < n && y < n)
	{
		ok = arr[x][y] == last;
		x += dx;
		y += dy;
	}

	return ok ? last : '.';
}

int main()
{
	int ts;
	scanf("%d\n", &ts);

	for (int t = 0; t < ts; t++)
	{
		scanf("%d\n", &n);

		arr = new string[n];

		for (int i = 0; i < n; i++)
		{
			getline(cin, arr[i]);
		}

		bool error = false;
		char winner = ' ';

		char w;

		if (!error)
		{
			w = line(0, 0, 1, 1);
			if (w != '.')
			{
				if (winner != ' ' && winner != w) error = true;
				else winner = w;
			}
		}

		if (!error)
		{
			w = line(0, n-1, 1, -1);
			if (w != '.')
			{
				if (winner != ' ' && winner != w) error = true;
				else winner = w;
			}
		}

		for (int i = 0; !error && i < n; i++)
		{
			w = line(0, i, 1, 0);
			if (w != '.')
			{
				if (winner != ' ' && winner != w) { error = true; break; }
				else winner = w;
			}

			w = line(i, 0, 0, 1);
			if (w != '.')
			{
				if (winner != ' ' && winner != w) { error = true; break; }
				else winner = w;
			}
		}

		if (error)
		{
			printf("Error\n");
		}
		else if (winner == ' ')
		{
			printf("Neither won\n");
		}
		else
		{
			printf("%c won\n", winner);
		}

		delete[] arr;
	}

	return 0;
}
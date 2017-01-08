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
		int n = rand() % (100 - 3 + 1) + 3;
		printf("%d\n", n);

		char** arr = new char*[n];

		for (int i = 0; i < n; i++)
		{
			arr[i] = new char[n];
			for (int j = 0; j < n; j++)
			{
				int r = rand() % 3;
				arr[i][j] = r == 0 ? '.' : r == 1 ? 'X' : 'O';
			}
		}

		int cnt = rand() % 10;
		for (int i = 0; i < cnt; i++)
		{
			int r = rand() % 20;
			int cr = rand() % 2;
			char c = cr == 0 ? 'X' : 'O'; 

			if (r >= 0 && r <= 2)
			{
				int row = rand() % n;
				for (int i = 0; i < n; i++)
				{
					arr[row][i] = c;
				}
			}
			else if (r >= 6 && r <= 8)
			{
				int col = rand() % n;
				for (int i = 0; i < n; i++)
				{
					arr[i][col] = c;
				}	
			}
			else if (r == 12)
			{
				for (int i = 0; i < n; i++)
				{
					arr[i][i] = c;
				}
			}
			else if (r == 13)
			{
				for (int i = 0; i < n; i++)
				{
					arr[n - i - 1][i] = c;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%c", arr[i][j]);
			}

			printf("\n");
		}

		for (int i = 0; i < n; i++)
		{
			delete[] arr[i];
		}

		delete[] arr;
	}

	return 0;
}
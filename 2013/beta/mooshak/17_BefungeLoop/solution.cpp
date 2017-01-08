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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
	int ts;
	scanf("%d\n", &ts);

	for (int t = 0; t < ts; t++)
	{
		vector<string> board;
		string line;
		while (getline(cin, line) && line != "#")
		{
			board.push_back(line);
		}

		int x = 0, y = 0, d = 0;

		int n = size(board),
			m = size(board[0]);

		bool*** visited = new bool**[n];

		for (int i = 0; i < n; i++)
		{
			visited[i] = new bool*[m];
			for (int j = 0; j < m; j++)
			{
				visited[i][j] = new bool[4];
				memset(visited[i][j], 0, 4);
			}
		}

		bool ends = false;
		while (true)
		{
			if (board[x][y] == '>')
			{
				d = 0;
			}
			else if (board[x][y] == 'v')
			{
				d = 1;
			}
			else if (board[x][y] == '<')
			{
				d = 2;
			}
			else if (board[x][y] == '^')
			{
				d = 3;
			}
			else if (board[x][y] == '@')
			{
				ends = true;
				break;
			}

			if (visited[x][y][d])
			{
				break;
			}

			visited[x][y][d] = true;

			x += dx[d];
			y += dy[d];
		}

		if (ends)
		{
			printf("Terminates\n");
		}
		else
		{
			printf("Infinite loop\n");
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				delete[] visited[i][j];
			}

			delete[] visited[i];
		}

		delete[] visited;
	}

	return 0;
}
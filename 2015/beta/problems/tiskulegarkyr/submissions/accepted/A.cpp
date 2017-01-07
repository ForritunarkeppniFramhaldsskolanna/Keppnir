#include <cstdio>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main()
{
	int N, M;
	scanf("%d %d\n", &N, &M);

	char **arr = new char*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new char[M];
		for (int j = 0; j < M; j++)
		{
			scanf("%c", &(arr[i][j]));
		}

		scanf("\n");
	}

	vector<ii> spot[2];

	int pat = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] != 'X')
				continue;

			stack<ii> S;
			S.push(ii(i, j));
			arr[i][j] = '#';

			while (!S.empty())
			{
				ii cur = S.top(); S.pop();
				spot[pat].push_back(cur);

				for (int di = -1; di <= 1; di++)
				{
					for (int dj = -1; dj <= 1; dj++)
					{
						if ((di == 0) ^ (dj == 0))
						{
							int ci = di + cur.first,
								cj = dj + cur.second;

							if (ci >= 0 && cj >= 0 && ci < N && cj < M && arr[ci][cj] == 'X')
							{
								arr[ci][cj] = '#';
								S.push(ii(ci, cj));
							}
						}
					}
				}
			}

			pat++;
		}
	}

	int mindist = 2147483647;

	for (vector<ii>::iterator it = spot[0].begin(); it != spot[0].end(); it++)
	{
		for (vector<ii>::iterator it2 = spot[1].begin(); it2 != spot[1].end(); it2++)
		{
			mindist = min(mindist, abs(it->first - it2->first) + abs(it->second - it2->second) - 1);
		}
	}

	printf("%d\n", mindist);
	return 0;
}
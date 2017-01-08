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

string a, b, c;

int idx[256];

int main()
{
	printf("Þraut:\n");
	getline(cin, a);
	getline(cin, b);
	getline(cin, c);

	set<char> cs;
	for (int i = 0; i < size(a); i++) if (a[i] >= 'A' && a[i] <= 'Z') cs.insert(a[i]);
	for (int i = 0; i < size(b); i++) if (b[i] >= 'A' && b[i] <= 'Z') cs.insert(b[i]);
	for (int i = 0; i < size(c); i++) if (c[i] >= 'A' && c[i] <= 'Z') cs.insert(c[i]);

	if (size(cs) > 10)
	{
		printf("Engin lausn\n");
	}
	else
	{
		int x = 0;
		for (set<char>::const_iterator it = cs.begin(); it != cs.end(); it++)
		{
			idx[static_cast<int>(*it)] = x++;
		}

		int* perm = new int[10];
		for (int i = 0; i < 10; i++) perm[i] = i;

		set<vector<int> > sols;

		do
		{
			int an = 0,
				bn = 0,
				cn = 0;

			bool ok = true, first = true;

			for (int i = 0, cnt = size(a); i < cnt; i++)
			{
				if (a[i] >= 'A' && a[i] <= 'Z')
				{
					if (first)
					{
						if (perm[idx[static_cast<int>(a[i])]] == 0)
						{
							ok = false;
							break;
						}

						first = false;
					}

					an = an * 10 + perm[idx[static_cast<int>(a[i])]];
				}
			}

			if (!ok) continue;

			first = true;
			for (int i = 0, cnt = size(b); i < cnt; i++)
			{
				if (b[i] >= 'A' && b[i] <= 'Z')
				{
					if (first)
					{
						if (perm[idx[static_cast<int>(b[i])]] == 0)
						{
							ok = false;
							break;
						}

						first = false;
					}

					bn = bn * 10 + perm[idx[static_cast<int>(b[i])]];
				}
			}

			if (!ok) continue;

			first = true;
			for (int i = 0, cnt = size(c); i < cnt; i++)
			{
				if (c[i] >= 'A' && c[i] <= 'Z')
				{
					if (first)
					{
						if (perm[idx[static_cast<int>(c[i])]] == 0)
						{
							ok = false;
							break;
						}

						first = false;
					}

					cn = cn * 10 + perm[idx[static_cast<int>(c[i])]];
				}
			}

			if (!ok) continue;

			if (ok && an + bn == cn)
			{
				vector<int> sol;
				for (set<char>::const_iterator it = cs.begin(); it != cs.end(); it++)
				{
					sol.push_back(perm[idx[static_cast<int>(*it)]]);
				}

				sols.insert(sol);
			}

		} while (next_permutation(perm, perm + 10));

		if (size(sols) == 0)
		{
			printf("Engin lausn\n");
		}
		else
		{
			for (set<vector<int> >::const_iterator sol = sols.begin(); sol != sols.end(); sol++)
			{
				printf("Lausn:\n");
				for (int i = 0; i < size(a); i++)
				{
					if (a[i] >= 'A' && a[i] <= 'Z')
					{
						printf("%d", (*sol)[idx[static_cast<int>(a[i])]]);
					}
					else
					{
						printf("%c", a[i]);
					}
				}

				printf("\n");

				for (int i = 0; i < size(b); i++)
				{
					if (b[i] >= 'A' && b[i] <= 'Z')
					{
						printf("%d", (*sol)[idx[static_cast<int>(b[i])]]);
					}
					else
					{
						printf("%c", b[i]);
					}
				}

				printf("\n");

				for (int i = 0; i < size(c); i++)
				{
					if (c[i] >= 'A' && c[i] <= 'Z')
					{
						printf("%d", (*sol)[idx[static_cast<int>(c[i])]]);
					}
					else
					{
						printf("%c", c[i]);
					}
				}

				printf("\n");
			}
		}
	}

	return 0;
}
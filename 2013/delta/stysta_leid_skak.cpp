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
#define INF 2147483647
typedef long long ll;
typedef pair<int, int> ii;
template <class T> int size(T x) { return x.size(); }

// assert or gtfo

struct node
{
	int cnt;
	int val;
	node* nxt;

	node(int n, node* nx)
	{
		val = n;
		nxt = nx;
		cnt = nx->cnt + 1;
	}

	node() { }
};

void add(queue<node*>& Q, bool* done, int x, int y, node* last)
{
	if (x >= 0 && x < 8 && y >= 0 && y < 8 && !done[x * 10 + y])
	{
		Q.push(new node(x * 10 + y, last));
		done[x * 10 + y] = true;
	}
}

int main()
{
	bool done[128];
	string line;

	printf("Upphafsreitur: ");
	getline(cin, line);

	int ax = line[0] - 'a',
		ay = line[1] - '1';

	printf("Endareitur: ");
	getline(cin, line);

	int bx = line[0] - 'a',
		by = line[1] - '1';

	int start = ax * 10 + ay,
		end = bx * 10 + by;

	memset(done, 0, 128);

	queue<node*> Q;
	node* frst = new node;
	frst->cnt = 0;
	frst->val = start;
	frst->nxt = NULL;
	Q.push(frst);
	done[start] = true;

	while (true)
	{
		node* cur = Q.front(); Q.pop();

		if (cur->val == end)
		{
			printf("Stysta leið: %d\n", cur->cnt);
			stack<int> S;
			for (node* at = cur; at != NULL; at = at->nxt)
				S.push(at->val);
			while (!S.empty())
			{
				printf("%c%c ", (S.top() / 10) + 'a', (S.top() % 10) + '1');
				S.pop();
			}

			printf("\n");
			break;
		}

		int x = cur->val / 10,
			y = cur->val % 10;

		add(Q, done, x + 2, y + 1, cur);
		add(Q, done, x + 2, y - 1, cur);
		add(Q, done, x - 2, y + 1, cur);
		add(Q, done, x - 2, y - 1, cur);
		add(Q, done, x + 1, y + 2, cur);
		add(Q, done, x + 1, y - 2, cur);
		add(Q, done, x - 1, y + 2, cur);
		add(Q, done, x - 1, y - 2, cur);
	}

	return 0;
}
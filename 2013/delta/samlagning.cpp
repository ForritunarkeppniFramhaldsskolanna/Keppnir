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
	printf("Tölur: ");
	string line;
	getline(cin, line);
	stringstream ss(line);
	priority_queue<int, vector<int>, greater<int> > pq;

	int tmp;
	while (ss >> tmp) pq.push(tmp);

	int cost = 0;
	while (true)
	{
		int cur = pq.top(); pq.pop();

		if (pq.empty())
		{
			printf("Samtals: %d\n", cur);
			printf("Minnsti kostnaður: %d\n", cost);
			break;
		}

		int nxt = pq.top(); pq.pop();
		cost += cur + nxt;
		pq.push(cur + nxt);
	}

	return 0;
}
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

vector<int> read_ints()
{
	string line;
	getline(cin, line);

	stringstream ss(line);
	vector<int> res;

	int tmp;
	while (ss >> tmp)
	{
		res.push_back(tmp);
	}

	return res;
}

int main()
{
	int ts;
	scanf("%d\n", &ts);

	for (int t = 0; t < ts; t++)
	{
		vector<int> a = read_ints(),
					b = read_ints();

		sort(all(a));

		if (a == b)
		{
			printf("Accepted\n");
		}
		else
		{
			printf("Wrong Answer\n");
		}
	}

	return 0;
}
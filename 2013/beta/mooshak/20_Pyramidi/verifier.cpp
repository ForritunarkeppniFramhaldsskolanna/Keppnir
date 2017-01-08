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
	ifstream in("3.in"),
			 out("3.out");

	int ts;
	in >> ts;

	bool ok = true;

	for (int t = 0; t < ts; t++)
	{
		int n;
		in >> n;

		int a, b;
		out >> a >> b;

		ok = ok && a * (a + 1) / 2 + b == n && b <= a;
	}

	printf("%s\n", ok ? "Correct" : "Incorrect");

	return 0;
}
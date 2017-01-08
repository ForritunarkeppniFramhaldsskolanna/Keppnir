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

vector<char> add(vector<char> a, vector<char> b)
{
	char carry = 0;
	int l = 0, r = 0, lcnt = size(a), rcnt = size(b);

	vector<char> res;
	while (l < lcnt && r < rcnt)
	{
		int cur = a[l] + b[r] + carry;
		res.push_back(cur % 10);
		carry = cur / 10;
		l++; r++;
	}

	while (l < lcnt)
	{
		int cur = a[l] + carry;
		res.push_back(cur % 10);
		carry = cur / 10;
		l++;
	}

	while (r < rcnt)
	{
		int cur = b[r] + carry;
		res.push_back(cur % 10);
		carry = cur / 10;
		r++;
	}

	if (carry)
	{
		res.push_back(carry);
	}

	return res;
}


vector<char> sub(vector<char> a, vector<char> b)
{
	char carry = 0;
	int l = 0, r = 0, lcnt = size(a), rcnt = size(b);

	vector<char> res;
	while (l < lcnt && r < rcnt)
	{
		int cur = a[l] - b[r] - carry;
		if (cur < 0)
		{
			cur += 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}

		res.push_back(cur);
		l++; r++;
	}

	while (l < lcnt)
	{
		int cur = a[l] - carry;
		if (cur < 0)
		{
			cur += 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}

		res.push_back(cur);
		l++;
	}

	while (r < rcnt)
	{
		int cur = - b[r] - carry;
		if (cur < 0)
		{
			cur += 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}

		res.push_back(cur);
		r++;
	}

	assert(carry == 0);

	while (size(res) > 1 && res[size(res) - 1] == 0)
	{
		res.pop_back();
	}

	return res;
}

bool lt(vector<char> a, vector<char> b)
{
	if (size(a) != size(b))
	{
		return size(a) < size(b);
	}

	for (int i = size(a) - 1; i >= 0; i--)
	{
		if (a[i] != b[i])
		{
			return a[i] < b[i];
		}
	}

	return false;
}

void display(vector<char> a)
{
	for (int i = size(a) - 1; i >= 0; i--)
	{
		printf("%d", a[i]);
	}
}

int main()
{
	int ts;
	scanf("%d\n", &ts);

	for (int t = 0; t < ts; t++)
	{
		int n, its;

		scanf("%d %d\n", &n, &its);

		vector<char> a, b;
		vector<char> ten;
		ten.push_back(0);
		ten.push_back(1);

		while (n)
		{
			a.push_back(n % 10);
			n /= 10;
		}

		b.push_back(5);

		a = add(a, add(a, add(a, add(a, a))));

		for (int it = 0; it < its; it++)
		{
			if (!lt(a, b))
			{
				a = sub(a, b);
				b = add(b, ten);
			}
			else
			{
				vector<char> tmp;
				
				if (a[size(a) - 1] != 0)
				{
					tmp.push_back(0);
					tmp.push_back(0);

					for (int i = 0, cnt = size(a); i < cnt; i++)
					{
						tmp.push_back(a[i]);
					}

					a = tmp;
				}

				tmp.clear();
				tmp.push_back(b[0]);
				tmp.push_back(0);
				for (int i = 1, cnt = size(b); i < cnt; i++)
				{
					tmp.push_back(b[i]);
				}

				b = tmp;
			}
		}

		display(b);
		printf("\n");
	}

	return 0;
}
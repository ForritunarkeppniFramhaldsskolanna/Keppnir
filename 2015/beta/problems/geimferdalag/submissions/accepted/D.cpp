#include <cstdio>
#include <utility>
#include <list>
#include <cmath>
#include <iostream>
using namespace std;

typedef pair<int, int> ii;
typedef list<ii> factorization;

factorization multiply(factorization a, factorization b)
{
    factorization res;

    factorization::iterator l = a.begin(), r = b.begin();
    while (l != a.end() && r != b.end())
    {
        if (l->first == r->first)
        {
            res.push_back(ii(l->first, l->second + r->second));
            l++; r++;
        }
        else if (l->first < r->first)
        {
            res.push_back(*l);
            l++;
        }
        else
        {
            res.push_back(*r);
            r++;
        }
    }

    while (l != a.end())
    {
        res.push_back(*l);
        l++;
    }

    while (r != b.end())
    {
        res.push_back(*r);
        r++;
    }

    return res;
}

factorization divide(factorization a, factorization b)
{
    factorization res;

    factorization::iterator l = a.begin(), r = b.begin();
    while (l != a.end() && r != b.end())
    {
        if (l->first == r->first)
        {
            res.push_back(ii(l->first, l->second - r->second));
            l++; r++;
        }
        else if (l->first < r->first)
        {
            res.push_back(*l);
            l++;
        }
        else
        {
            res.push_back(ii(r->first, -r->second));
            r++;
        }
    }

    while (l != a.end())
    {
        res.push_back(*l);
        l++;
    }

    while (r != b.end())
    {
        res.push_back(ii(r->first, -r->second));
        r++;
    }

    return res;
}

unsigned long long powmod(unsigned long long b, int p, unsigned long long m)
{
    unsigned long long res = 1 % m;
    while (p)
    {
        if (p & 1) res = (res * b) % m;
        b = (b * b) % m;
        p >>= 1;
    }

    return res;
}

int main()
{
	int n;
    scanf("%d\n", &n);

    factorization* fact = new factorization[10000];
    for (int i = 2; i < 10000; i++)
    {
        int tmp = i;
        for (int j = 2; j*j <= i; j = j == 2 ? 3 : j + 2)
        {
            int p = 0;
            while (tmp % j == 0)
            {
                p++;
                tmp /= j;
            }

            if (p > 0)
            {
                fact[i].push_back(ii(j, p));
            }
        }

        if (tmp > 1)
        {
            fact[i].push_back(ii(tmp, 1));
        }
    }

    factorization den = fact[1];

    int ysum = 0;
    for (int i = 0; i < n; i++)
    {
        int cury;
        scanf("%d", &cury);
        ysum += cury;
        factorization yfactorial = fact[1];
        for (int j = 2; j <= cury; j++)
        {
            yfactorial = multiply(yfactorial, fact[j]);
        }

        den = multiply(den, yfactorial);
    }

    factorization num = fact[1];

    for (int i = 2; i <= ysum; i++)
    {
        num = multiply(num, fact[i]);
    }

    factorization frac = divide(num, den);

    unsigned long long res = 1;

    for (factorization::iterator it = frac.begin(); it != frac.end(); it++)
    {
        res = (res * powmod(it->first, it->second, 1000000007)) % 1000000007;
    }

    cout << res << endl;

	return 0;
}

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

// inline double abs(double n)
// {
//     return n < 0 ? -n : n;
// }

int main()
{
	int N;
	scanf("%d\n", &N);

	double a0, anp1;
	scanf("%lf\n%lf\n", &a0, &anp1);

	double *c = new double[N + 2];
	for (int i = 1; i <= N; i++)
		scanf("%lf\n", &(c[i]));

	double low = -2000,
		   high = 2000,
		   mid;

    while (true)
    {
    	mid = (low + high) / 2;

    	double last,
    		   cur = a0,
    		   next = mid;
    	
    	for (int i = 1; i <= N; i++)
    	{
    		last = cur;
    		cur = next;
    		next = 2 * (cur + c[i]) - last;
    	}

    	if (abs(anp1 - next) < 1E-9)
    	{
            cout << floor(mid * 100) / 100 << endl;
    		break;
    	}
    	else if (next < anp1)
    	{
    		low = mid;
    	}
    	else	
    	{
    		high = mid;
    	}
    }

	return 0;
}

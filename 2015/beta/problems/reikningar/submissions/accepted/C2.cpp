#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int n;
	double a0, anp1;
	scanf("%d\n%lf\n%lf\n", &n, &a0, &anp1);

	double* c = new double[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%lf\n", c + i);
	}

	double s = 0;
	for (int i = 1; i <= n; i++)
	{
		s += i * c[n - i];
	}

	//printf("%0lf\n", a0 + (anp1 - a0 - 2 * s) / (n + 1));
	printf("%0.2lf\n", a0 + (anp1 - a0 - 2 * s) / (n + 1));
	return 0;
}
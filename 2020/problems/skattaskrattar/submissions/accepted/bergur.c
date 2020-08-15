#include <math.h>
#include <stdio.h>
#define EPS 1e-9
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int();
typedef struct { double x, y; } par;
void rot(double* x, double* y, double a)
{
	double xx = *x, yy = *y;
	*x = cos(a)*xx - sin(a)*yy;
	*y = sin(a)*xx + cos(a)*yy;
}
int foo(double x1, double y1, double x2, double y2, double a1, double b1, double a2, double b2, double* r)
{
	if (fabs((y2 - y1)/(x2 - x1) - (b2 - b1)/(a2 - a1)) < EPS) return 0;
	x2 -= x1; y2 -= y1;
	a1 -= x1; b1 -= y1;
	a2 -= x1; b2 -= y1;
	double a = atan2(y2, x2), t = 0.0;
	rot(&x2, &y2, -a);
	rot(&a1, &b1, -a);
	rot(&a2, &b2, -a);
	if (b1 > EPS && b2 > EPS || b1 < -EPS && b2 < -EPS) return 0;
	if (a1 > a2)
	{
		double s = a1; a1 = a2; a2 = s;
		s = b1; b1 = b2; b2 = s;
	}
	*r = a1 + b1/(b1 - b2)*(a2 - a1);
	//printf(">> %f %f %f %f %f\n", *r, a1, b1, a2, b2);
	if (*r > x2 + EPS || *r < -EPS) return 0;
	rot(r, &t, a);
	*r += x1;
	return 1;
}

int main()
{
	int n = get_int(), m = get_int(), i, j;
	par a[n], b[m];
	rep(i, n - 1) a[i].x = get_int(), a[i].y = get_int();
	a[i].x = get_int(), a[i].y = 1000000000000.0;
	rep(i, m - 1) b[i].x = get_int(), b[i].y = get_int();
	b[i].x = get_int(), b[i].y = 1000000000000.0;
	i = j = 1;
	double x[4] = {0.0, a[0].y, 0.0, b[0].y}, y[4] = {0.0, 1.0*a[0].y*a[0].x/100.0, 0.0, 1.0*b[0].y*b[0].x/100.0}, r, rr = -1.0;
	while (i != n + 1 && j != m + 1)
	{
		if (foo(x[0], y[0], x[1], y[1], x[2], y[2], x[3], y[3], &r))
		{
			if (fabs(rr - r) > 1e-4) printf("%.12f\n", rr = r);
		}
		if (j == m || x[1] < x[3])
		{
			x[0] = x[1], y[0] = y[1];
			x[1] = a[i].y;
			y[1] = y[0] + (x[1] - x[0])*a[i].x/100.0;
			i++;
		}
		else
		{
			x[2] = x[3], y[2] = y[3];
			x[3] = b[j].y;
			y[3] = y[2] + (x[3] - x[2])*b[j].x/100.0;
			j++;
		}
	}
	return 0;
}

int get_int()
{
	int sgn = 1, ret = 0;
	char c  = getchar();
	while (1)
	{
		if (c == EOF) return EOF;
		if (c >= '0' && c <= '9') break;
		if (c == '-')
		{
			c = getchar();
			if (c < '0' || c > '9') continue;
			sgn = -1;
			break;
		}
		c = getchar();
	}

	while (1)
	{
		ret = ret*10 + c - '0';
		c = getchar();
		if (c < '0' || c > '9') return sgn*ret;
	}
}

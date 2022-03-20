#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define per(E, F) for (E = (F) - 1; E >= 0; E--)
#define MAXN 100
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }
int get_int()
{
	int r = 0, c = getchar(), s = 1;
	while (c != '-' && c < '0' || c > '9') c = getchar();
	while (c == '-') s *= -1, c = getchar();
	while (c >= '0' && c <= '9') r = r*10 + c - '0', c = getchar();
	return s*r;
}
int d[MAXN][MAXN][MAXN], c[MAXN][3];
int foo(int x, int y, int z)
{ // er hægt fyrir daga [1, x] með y samlokur af gerð 1 og z a hinni gerð
	if (y < 0 || z < 0) return 0;
	if (x == -1) return 1;
	if (d[x][y][z] != -1) return d[x][y][z];
	y += c[x][0], z += c[x][1];
	d[x][y][z] = foo(x - 1, y, z - 2) || foo(x - 1, y - 1, z - 1);
	return d[x][y][z];
}

int main()
{
	int i, j, l, n = get_int(), k = get_int();
	rep(i, MAXN) rep(j, MAXN) rep(l, MAXN) d[i][j][l] = -1;
	int a[n], b[n], cc[3] = {0, 0};
	rep(i, n) c[i][0] = c[i][1] = 0;
	rep(i, n) a[i] = get_int();
	rep(i, n) a[i] = a[i] < 4 ? 2 : (a[i] == 4 ? 0 : 1);
	rep(i, n) b[i] = get_int();
	rep(i, n) if (1 <= b[i] && b[i] <= k) c[b[i] - 1][a[i]]++;
	rep(i, n) if (b[i] > k) cc[a[i]]++;
	printf("%s\n", foo(k - 1, cc[0], cc[1]) ? "Jebb" : "Neibb");
	return 0;
}

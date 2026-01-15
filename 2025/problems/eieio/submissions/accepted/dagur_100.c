#include <stdio.h>

static inline int det(int a, int b, int c, int d) {
	return a * d - b * c;
}

int main() {
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	int den = det(1, 1, 2, 4);
	if (den == 0) {
		puts("Rong talning");
		return 0;
	}
	int people = det(n, 1, m, 4);
	int sheep = det(1, n, 2, m);
	if (people % den != 0 || sheep % den != 0) {
		puts("Rong talning");
		return 0;
	}
	people /= den;
	sheep /= den;
	if (people < 0 || sheep < 0) {
		puts("Rong talning");
		return 0;
	}

	printf("%d\n", sheep);

	return 0;
}

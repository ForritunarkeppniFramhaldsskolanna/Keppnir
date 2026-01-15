#include <stdio.h>

int main() {
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	if (n == m) {
		puts("Dufur passa fullkomlega");
	} else if (n > m) {
		puts("Dufur passa ekki");
	} else {
		puts("Dufur passa");
	}

	return 0;
}

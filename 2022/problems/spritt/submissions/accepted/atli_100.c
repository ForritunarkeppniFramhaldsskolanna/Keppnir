#include <stdio.h>

int main() {
    int n, x, y;
    scanf("%d %d", &n, &x);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &y);
        x -= y;
    }
    if(x >= 0) printf("Jebb\n");
    else printf("Neibb\n");
}

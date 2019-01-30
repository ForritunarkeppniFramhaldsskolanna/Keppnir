
#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int curr_min;
	scanf("%d", &curr_min);

	for(int i=1; i<n; i++){
		int a;
		scanf("%d", &a);
		if(curr_min > a) curr_min = a;
	}
	printf("%d", curr_min);
}

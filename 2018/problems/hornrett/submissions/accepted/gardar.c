
#include <stdio.h>
int main(){
	int a,b,c;
	scanf("%d %d %d", &a, &b, &c);
	unsigned long long al, bl, cl;
	al = a, bl = b, cl = c;
	if(al > cl){
		unsigned long long t = al;
		al = cl;
		cl = t;
	}
	if(bl > cl){
		unsigned long long t = bl;
		bl = cl;
		cl = t;
	}

	if(al*al + bl*bl == cl*cl) printf("%lld", al*bl/2);
	else printf("-1");
}

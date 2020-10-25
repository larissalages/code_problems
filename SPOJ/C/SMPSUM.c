// https://www.spoj.com/problems/SMPSUM/

#include <stdio.h>

int main(void) {
	int a,b, sum=0;
	scanf("%d%d",&a,&b);
	
	for(int i=a;i<=b;i++){
		sum = sum + (i*i);
	}
	printf("%d",sum);
	return 0;
}

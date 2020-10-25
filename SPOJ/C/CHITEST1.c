// https://www.spoj.com/problems/CHITEST1/

#include <stdio.h>

int main(void) {
	int n,a,b;
	int result[n];
	
	scanf("%d", &n);

	for(int i=0;i<n;i++){
		scanf("%d %d", &a, &b);
		result[i] = a + b;
	}
	for(int j=0;j<n;j++){
		printf("%d\n", result[j]);
	}

	return 0;
}

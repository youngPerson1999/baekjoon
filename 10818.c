#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int N,n,max=-1000000,min=1000000;
	do {
		scanf("%d", &N);
	} while (N < 1 || N>1000000);

	int *num = malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		num[i] = n;	
	}
	for (int i = 0; i < N; i++) {
		if (num[i] >= max) max = num[i];
		if (num[i] <= min)	min = num[i];
	}
	printf("%d %d", min, max);
	
	free(num);
	return 0;
}
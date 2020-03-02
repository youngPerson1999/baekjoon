#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int T;
	int max,min;
	
	scanf("%d", &T);

	int *N = malloc(sizeof(int)*T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &N[i]);
	}
	max = N[0];	min = N[0];
	for (int i = 0; i < T; i++) {
		if (N[i] > max)	max = N[i];
		if (N[i] < min)	min = N[i];
	}

	printf("%d", min*max);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int N,n;
	do {
		scanf("%d", &N);
	} while (N < 1 || N>1000);

	int *num = malloc(sizeof(int)*N);	//int *arr = malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		num[i] = n;	
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = i; j >= 0; j--) {
			if (j > 0 && num[j - 1] > num[j]) {
				n = num[j - 1];	num[j - 1] = num[j];	num[j] = n;
			}
		}
	}
	for (int i = 0; i < N; i++)	printf("%d\n", num[i]);
	free(num);
	return 0;
}
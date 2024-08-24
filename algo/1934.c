#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int main(void) {
	int T;
	scanf("%d", &T);	getchar();
	int *A = malloc(sizeof(int)*T);
	int *B = malloc(sizeof(int)*T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < T; i++) {
		scanf("%d", &B[i]);
	}
	for (int i = 0; i < T; i++) {
		printf("%d", A[i]);
	}
	return 0;
}

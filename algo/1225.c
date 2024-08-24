#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main(void) {
	int asum = 0, bsum = 0;
	char*A = malloc(sizeof(char) * 10001);
	char*B = malloc(sizeof(char) * 10001);

	scanf("%s", A);
	scanf("%s", B);

	for (int i = 0; A[i] != NULL; i++) {
		asum += (A[i] - '0');
	}
	for (int j = 0; B[j] != NULL; j++) {
		bsum += (B[j] - '0');
	}

	printf("%d", asum*bsum);

	free(A);
	free(B);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int compare(void* first, void* second) {
	if (*(int*)first > *(int*)second) return 1;
	else if (*(int*)first < *(int*)second) return -1;
	else return 0;
}
int main(void) {
	int T, sum = 0;
	scanf("%d", &T);	getchar();
	int *A = malloc(sizeof(int)*T);
	int *B = malloc(sizeof(int)*T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &A[i]);
	}
	qsort(A, T, sizeof(int), compare);
	for (int i = 0; i < T; i++) {
		scanf("%d", &B[i]);
	}
	qsort(B, T, sizeof(int), compare);
	for (int i = 0; i < T; i++)sum += A[i] * B[T - i - 1];
	printf("%d", sum);
	return 0;
}

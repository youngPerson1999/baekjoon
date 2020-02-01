#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int C, N, n, cnt;
	double sum, aver;
	scanf("%d", &C);
	for (int i = 0; i < C; i++) {
		cnt = 0;	sum = 0;	aver = 0;
		scanf("%d", &N);
		int *num = malloc(sizeof(int)*N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &n);	num[j] = n;	sum += n;
		}
		aver = sum / N;
		for (int j = 0; j < N; j++) if (num[j] > aver) cnt++;
		printf("%.3f%%", (double)cnt / N * 100);
		if (i < C - 1) printf("\n");
	}
	return 0;
}
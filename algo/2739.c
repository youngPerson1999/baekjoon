#include<stdio.h>

int main(void) {
	int N, i = 1;
	do {
		scanf("%d", &N);
	} while (N < 1 || N>10);
	for (i; i < 10; i++) {
		printf("%d * %d = %d\n", N, i, N*i);
	}
	return 0;
}
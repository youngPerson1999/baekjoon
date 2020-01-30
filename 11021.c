#include<stdio.h>

int main(void) {
	int num, i, a, b,sum[1000];
	scanf("%d", &num);
	for (i = 0; i <num; i++) {
		do {
			scanf("%d %d", &a, &b);
		} while (a < 0 || a>10 || b < 0 || b>10);
		sum[i] = a + b;
	}
	for (i = 0; i < num; i++) {
		printf("Case #%d: %d\n", i + 1, sum[i]);
	}
	return 0;
}
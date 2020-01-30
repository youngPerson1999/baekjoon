#include<stdio.h>

int main(void) {
	int num, i, a[1000], b[1000],sum[1000];
	scanf("%d", &num);
	for (i = 0; i <num; i++) {
		do {
			scanf("%d %d", &a[i], &b[i]);
		} while (a[i] < 0 || a[i]>10 || b[i] < 0 || b[i]>10);
		sum[i] = a[i] + b[i];
	}
	for (i = 0; i < num; i++) {
		printf("Case #%d: %d + %d = %d\n", i + 1, a[i], b[i], sum[i]);
	}
	return 0;
}
#include<stdio.h>

int main(void) {
	int T, a, b, i, rst[100];
	scanf("%d", &T);
	for (i = T; i > 0; i--) {
		do {
			scanf("%d  %d", &a, &b);
		} while (a <= 0 || a >= 10 || b <= 0 || b >= 10);
		rst[i] = a + b;
	}
	for (i = T; i > 0; i--) {
		printf("%d\n", rst[i]);
	}
	return 0;
}
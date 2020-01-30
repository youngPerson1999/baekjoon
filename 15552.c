#include<stdio.h>

int main(void) {
	int num, i, a, b;
	do {
		scanf("%d", &num);
	} while (num > 1000000);
	for (i = num; i > 0; i--) {
		do {
			scanf("%d %d", &a, &b);
		} while (a < 1 || a>1000 || b < 1 || b>1000);
		printf("%d\n", a + b);
	}
	return 0;
}
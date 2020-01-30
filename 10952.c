#include<stdio.h>

int main(void) {
	int a = 1, b = 1;
	while (1) {
		do {
			scanf("%d %d", &a, &b);
			if (a == 0 && b == 0) break;
		} while (a <= 0 || a >= 10 || b <= 0 || b >= 10);
		if (a != 0 || b != 0) printf("%d\n", a + b);
		else break;
	}
	return 0;
}
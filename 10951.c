#include<stdio.h>

int main(void) {
	int a = 1, b = 1;
	while (scanf("%d %d", &a, &b)!=EOF) {
		if (a <= 0 || a >= 10 || b <= 0 || b >= 10) continue;
		if (a != 0 || b != 0) printf("%d\n", a + b);
	}
	return 0;
}
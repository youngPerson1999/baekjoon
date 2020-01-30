#include<stdio.h>

int main(void) {
	int num, cpy, tmp, cyc = 100, cnt = 0;
	do {
		scanf("%d", &num);
	} while (num < 0 || num > 99);
	cpy = num;
	while (num != cyc) {
		tmp = cpy % 10 + cpy / 10;
		cpy = (cpy % 10) * 10 + tmp % 10;
		cyc = cpy;
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}
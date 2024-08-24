#include<stdio.h>

int main(void) {
	int a, b, c, rst, cnt[10] = { 0 }, i;
	do {
		scanf("%d", &a);
	} while (a < 100 || a >= 1000);
	do {
		scanf("%d", &b);
	} while (b < 100 || b >= 1000);
	do {
		scanf("%d", &c);
	} while (c < 100 || c >= 1000);

	rst = a * b*c;

	for (i = rst; i > 0; i = i / 10) {
		cnt[i % 10]++;
	}
	for (i = 0; i < 10; i++) printf("%d\n", cnt[i]);
	return 0;
}
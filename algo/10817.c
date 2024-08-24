#include<stdio.h>

int main(void) {
	int a, b, c, mid;
	
	do {
		scanf("%d", &a);
	} while (a < 1 || a>100);
	do {
		scanf("%d", &b);
	} while (b < 1 || b>100);
	do {
		scanf("%d", &c);
	} while (c < 1 || c>100);
	mid = a;
	if (mid >= b && b >= c) mid = b;
	else if (mid >= c && c >= b)mid = c;
	else if (mid <= b && mid <= c) {
		if (b >= c) mid = c;
		else mid = b;
	}

	printf("%d", mid);
	
	return 0;
}
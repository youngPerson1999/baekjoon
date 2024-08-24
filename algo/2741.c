#include<stdio.h>

int main(void) {
	int num, i;
	do {
		scanf("%d", &num);
	} while (num > 100000);
	for (i = 1; i <= num; i++) {
		printf("%d\n", i);
	}
	return 0;
}
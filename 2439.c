#include<stdio.h>

int main(void) {
	int num, i, j, k;
	do {
		scanf("%d", &num);
	} while (num < 1 || num>100);
	for (i = 0; i < num; i++) {
		for (k = num-1; k > i; k--) printf(" ");
		for (j = 0; j <= i; j++) printf("*");
		printf("\n");
	}
	return 0;
}
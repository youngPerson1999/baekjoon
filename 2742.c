#include<stdio.h>

int main(void) {
	int num, i;
	do {
		scanf("%d", &num);
	} while (num > 100000);
	for (i = num; i > 0; i--) {
		printf("%d\n", i);
	}
	return 0;
}
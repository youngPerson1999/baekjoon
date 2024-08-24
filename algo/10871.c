#include<stdio.h>

int main(void) {
	int num, i, x, arr[10000];
	do {
		scanf("%d %d", &num,&x);
	} while (num < 1 || num>10000 || x < 1 || x>10000);
	for (i = 0; i < num; i++) {
		do {
			scanf("%d", &arr[i]);
		} while (arr[i] < 1 || arr[i]>10000);
	}
	for (i = 0; i < num; i++) {
		if (x > arr[i]) printf("%d ", arr[i]);
	}
	return 0;
}
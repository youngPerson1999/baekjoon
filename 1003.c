#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int T, num, prev, now, next;	int zero = 0, one = 0;

	scanf("%d", &T);
	getchar();

	for (int i = 0; i < T; i++) {
		scanf("%d", &num);
		if (num == 0) { zero = 1;	one = 0; }
		else if (num == 1) { zero = 0;	one = 1; }
		else {
			prev = 0;	now = 1;
			for (int j = 0; j < num; j++) {
				next = prev + now;
				if (j < num - 1) { prev = now;	now = next; }
			}
			zero = prev;	one = now;
		}
		printf("%d %d", zero, one);
		if (i < T - 1) printf("\n");
	}

	
	return 0;
}
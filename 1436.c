#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int hellnum(int n);
int checkhell(unsigned int i);

int main(void) {
	int n;
	do {
		scanf("%d", &n);
	} while (n < 0 || n > 10000);
	
	printf("%d", hellnum(n));

	return 0;

}

int hellnum(int n) {
	unsigned int i, cnt = 0, hell = 666;

	for (i = 666; cnt < n; i++) {
		if (checkhell(i)) cnt++;
		hell = i;
	}

	return hell;
}

int checkhell(unsigned int i) {
	int cnt = 0, check = 0;
	while (i != 0) {
		if (i % 10 == 6) {
			cnt++; i /= 10;
		}
		else {
			cnt = 0; i /= 10;
		}
		if (cnt == 3) {
			check = 1;	break;
		}
	}
	return check;
}

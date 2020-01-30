#include<stdio.h>

int find(int N);

int main(void) {
	int N;
	do {
		scanf("%d", &N);
	} while (N < 1 || N>1000);
	printf("%d", find(N));
	return 0;
}
int find(int N) {
	int i, cnt = 0, tmp;
	for (i = 1; i <= N; i++) {
		if (i < 100) cnt++;
		else if (i >= 100 && i < 1000) {
			tmp = i;
			if (((tmp / 10) % 10) - (tmp % 10) == ((tmp / 100) % 10) - ((tmp / 10) % 10)) cnt++;
		}
	}
	return cnt;
}
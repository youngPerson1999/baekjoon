#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int check(int n);

int main(void) {
	int T, num, cnt = 0;
	scanf("%d", &T);
	getchar();

	int *prime = malloc(sizeof(int)*T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &num);
		prime[i] = num;
	}

	for (int i = 0; i < T; i++) {
		if (check(prime[i])) cnt++;
	}
	printf("%d", cnt);
	return 0;
}
int check(int n) {
	if (n == 1) return 0;
	for (int i = 2; i < n; i++) {
		if (n%i == 0) return 0;
	}
	return 1;
}
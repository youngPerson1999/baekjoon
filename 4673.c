#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int selfnum(int n);
int limit = 10000;
int main(void) {
	int n, cnt = 0, count = 0;
	int*num = malloc(sizeof(int) * (limit + 1));
	for (int i = 1; i < limit; i++) num[i] = i;
	for (int i = 1; i < limit; i++) {
		n = selfnum(i);
		num[n] = 0;			//self number 아닌 숫자 0으로 변환
		if (num[i] != 0) cnt++;
	}
	for (int i = 1; i < limit; i++) {
		if (num[i] == 0) continue;
		printf("%d", num[i]);	count++;
		if (count < cnt) printf("\n");
	}
	free(num);
	return 0;
}
int selfnum(int n) {		//self number 구하는 알고리즘
	int tmp = n;
	for (int i = n; i > 0; i /= 10) {
		tmp += i % 10;
	}
	if (tmp >= limit) return 0;	//if self number가 limit이상이면 0반환
	return tmp;
}
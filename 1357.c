#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int Rev(int n);

int main(void) {
	int X, Y;

	scanf("%d %d", &X, &Y);
	
	int reversesum = Rev(X) + Rev(Y);

	printf("%d", Rev(reversesum));

	return 0;
}
int Rev(int n) {
	int reverse = 0;

	for (;n>0;n/=10,reverse*=10) {
		reverse += n % 10;
	}
	return reverse/10;
}
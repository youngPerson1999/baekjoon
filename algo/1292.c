#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int special(int n);

int main(void) {
	int A, B;

	scanf("%d %d", &A, &B);
	  
	printf("%d", special(B) - special(A - 1));		//sum until order B - sum until order A-1

	return 0;
}
int special(int n) {
	int sum = 0, cnt = 0;
	for (int i = 1; cnt<n; i++) {
		for (int j = 1; j <= i; j++) {
			sum += i;	cnt++;
			if (cnt == n) break;
		}
		if (cnt == n) break;
	}
	return sum;
}
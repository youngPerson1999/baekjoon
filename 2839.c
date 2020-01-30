#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int f = 5, t = 3;
int main(void) {
	
	int N, remind = 0, fshare, tshare;
	scanf("%d", &N);
	fshare = N / f;
	if (N%f == 0) printf("%d", N / f);
	else {
		for (;fshare>=0;fshare--) {
			remind=N-fshare*f;
			if (remind%t == 0) {
				tshare = remind / t;
				printf("%d", fshare + tshare);
				return 0;
			}
		}
		printf("%d", -1);
	}
	
	return 0;
}
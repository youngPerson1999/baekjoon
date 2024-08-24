#include<stdio.h>

int main(void) {
	int E, S, M, year = 0;
	do {
		scanf("%d", &E);
	} while (E < 1 || E>15);
	do {
		scanf("%d", &S);
	} while (S < 1 || S>28);
	do {
		scanf("%d", &M);
	} while (M < 1 || M>19);
	while (E != 0 && S != 0 && M != 0) {
		if (E != 0 && S != 0 && M != 0) {
			E--;	S--;	M--;	year++;
		}
		if (E == 0 && S == 0 && M == 0) break;
		if (E == 0) E = 15;
		if (S == 0) S = 28;
		if (M == 0) M = 19;
	}
	printf("%d", year);
	return 0;
}
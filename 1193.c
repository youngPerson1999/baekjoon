#include<stdio.h>

int main(void) {
	int x, frtnum = 0, frtsum = 1, bcknum = 0, bcksum = 1, check, cnt = 0, frtcpy, bckcpy;

	do {
		scanf("%d", &x);
	} while (x < 1 || x>10000000);

	while (frtsum<=x) {
		frtsum += frtnum * 4 + 1;
		frtnum++;
	}
	
	check = 2 * frtnum - 1;
	do {
		if (frtsum == x) break;
		else if (cnt < check) {
			frtsum--;	cnt++;	frtcpy = cnt;
		}
		else if (cnt >= check) {
			frtsum--; frtcpy--;
		}
	} while (1);

	while (bcksum <= x) {
		bcksum += bcknum * 4 + 3;
		bcknum++;
	}
	check = 2 * bcknum;	cnt = 0;
	do {
		if (bcksum == x) break;
		else if (cnt < check) {
			bcksum--;	cnt++;	bckcpy = cnt;
		}
		else if (cnt >= check) {
			bcksum--; bckcpy--;
		}
	} while (1);

	printf("%d/%d", frtcpy, bckcpy);

	return 0;
}
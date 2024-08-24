#include<stdio.h>

int main(void) {
	int score[1000], test, i, max = 0;
	double change[1000] = { 0 }, aver = 0;
	do {
		scanf("%d", &test);
	} while (test > 1000);
	for (i = 0; i < test; i++) {
		do {
			scanf("%d", &score[i]);
		} while (score[i] < 0 || score[i]>100);
		if (score[i] > max) max = score[i];
	}
	for (i = 0; i < test; i++) {
		change[i] = (double)score[i] / max * 100;
		aver += change[i];
	}
	aver /= test;
	printf("%f", aver);
	return 0;
}
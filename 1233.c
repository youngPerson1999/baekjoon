#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	int s1, s2, s3;

	scanf("%d %d %d", &s1, &s2, &s3);

	int *sum = malloc(sizeof(int)*(s1 + s2 + s3 + 1));
	memset(sum, 0, sizeof(int)*(s1 + s2 + s3 + 1));
	int order = 1;	int max = 0;
	for (int i = 1; i <= s1; i++)
		for (int j = 1; j <= s2; j++) 
			for (int k = 1; k <= s3; k++) {
				sum[i + j + k]++;
				//printf("s1 + s2 + s3 =%2d, count=%2d, order=%2d\n", i + j + k, sum[i + j + k],order++);	//Check the sum count
			}
	for (int i = 3; i < s1 + s2 + s3 + 1; i++) {
		//printf("sum[%2d]=%2d\n", i, sum[i]);				//Check again if sum count imported right
		if (sum[i] > max) {
			max = sum[i];	order = i;
		}
	}
	//printf("max count is %d, max is %2d", max, order);	//Check max and its order
	printf("%d", order);

	free(sum);
	return 0;
}

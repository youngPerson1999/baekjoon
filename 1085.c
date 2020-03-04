#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int x, y, w, h;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	int minx = x < (w - x) ? x : w - x;
	int miny = y < (h - y) ? y : h - y;

	printf("%d", minx < miny ? minx : miny);

	return 0;
}
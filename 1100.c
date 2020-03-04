#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZE 8

int isF(char *string, int line);				//F갯수 측정 함수

int main(void) {
	
	char *CSboard = malloc(sizeof(char)*SIZE);	// 체스판 한줄 크기 == SIZE
	int line = 1, Fnumber = 0;					//line number

	for (int i = 0; i < SIZE; i++,line++) {
		scanf("%s", CSboard);					//한줄입력
		Fnumber += isF(CSboard, line);
	}
	
	printf("%d", Fnumber);

	return 0;
}
int isF(char *string, int line) {
	int f = 0;
	if (line % 2) {							//홀수번째 줄
		for (int i = 0; i < SIZE; i+=2) {
			if (string[i] == 'F')	f++;
		}
	}
	else {									//짝수번째 줄
		for (int i = 1; i < SIZE; i+=2) {
			if (string[i] == 'F')	f++;
		}
	}
	return f;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZE 8

int isF(char *string, int line);				//F���� ���� �Լ�

int main(void) {
	
	char *CSboard = malloc(sizeof(char)*SIZE);	// ü���� ���� ũ�� == SIZE
	int line = 1, Fnumber = 0;					//line number

	for (int i = 0; i < SIZE; i++,line++) {
		scanf("%s", CSboard);					//�����Է�
		Fnumber += isF(CSboard, line);
	}
	
	printf("%d", Fnumber);

	return 0;
}
int isF(char *string, int line) {
	int f = 0;
	if (line % 2) {							//Ȧ����° ��
		for (int i = 0; i < SIZE; i+=2) {
			if (string[i] == 'F')	f++;
		}
	}
	else {									//¦����° ��
		for (int i = 1; i < SIZE; i+=2) {
			if (string[i] == 'F')	f++;
		}
	}
	return f;
}
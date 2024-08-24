#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int order = 0;
void push(int *stack, int x);
int pop(int *stack);
int top(int *stack);

int main(void) {
	int N, x;
	
	do {
		scanf("%d", &N);
	} while (N < 1 || N>10000);
	getchar();

	int *stack = malloc(sizeof(int)*N);	//�ִ� ũ��� stack size ����

	for (int i = 0; i < N; i++) {
		char insert[15] = { NULL };	//��� NULL�� �ʱ�ȭ, �ִ� 6�ڸ� �����̹Ƿ� ���ڿ� ũ��� 15ĭ
		gets(insert);
		//printf("%s", insert);
		if (strstr(insert, "push") != NULL) {	//�߶���ϹǷ�  insert ���ڿ��� push�� �ִ��� �ľ�
			char *cut = strtok(insert, " ");	//insert�� push�� x�� ������ ���� strtok
			cut = strtok(NULL, " ");			//"push"�� �ѱ�� �����κ��� cut�� ����
			x = atoi(cut);						//�����κ��� ������ ��ȯ
			//printf("%d", x);
			push(stack, x);
			continue;
		}
		else if (strcmp(insert, "pop") == 0)	printf("%d", pop(stack));
		else if (strcmp(insert, "empty") == 0) {
			if (order == 0) printf("1");
			else printf("0");
		}
		else if (strcmp(insert, "size") == 0) printf("%d", order);
		else if (strcmp(insert, "top") == 0) printf("%d", top(stack));

		if (i < N - 1) printf("\n");	//\n�� ������ �������� ����
	}
	
	free(stack);
	return 0;
}
void push(int *stack, int x) {
	stack[order] = x;
	order++;
}
int pop(int *stack) {
	int tmp = -1;
	if (order != 0) {
		tmp = stack[order - 1];
		stack[order - 1] = NULL;
		order--;
	}
	return tmp;
}
int top(int *stack) {
	int tmp = -1;
	if (order != 0) tmp = stack[order - 1];
	return tmp;
}
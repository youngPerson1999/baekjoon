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

	int *stack = malloc(sizeof(int)*N);	//최대 크기로 stack size 결정

	for (int i = 0; i < N; i++) {
		char insert[15] = { NULL };	//계속 NULL로 초기화, 최대 6자리 정수이므로 문자열 크기는 15칸
		gets(insert);
		//printf("%s", insert);
		if (strstr(insert, "push") != NULL) {	//잘라야하므로  insert 문자열에 push가 있는지 파악
			char *cut = strtok(insert, " ");	//insert를 push와 x로 나누기 위해 strtok
			cut = strtok(NULL, " ");			//"push"를 넘기고 정수부분을 cut에 넣음
			x = atoi(cut);						//정수부분을 정수로 변환
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

		if (i < N - 1) printf("\n");	//\n은 마지막 전까지만 실행
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
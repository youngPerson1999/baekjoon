#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main(void) {
	int T, cnt = 0, result;
	scanf("%d", &T);
	getchar();				//���� �ʱ�ȭ \n�� str�� �ԷµǴ� ���� ����
	char str[80];
	for (int i = 0; i < T; i++) {
		gets(str);	result = 0;	cnt = 0;	//O,X �Է�, ���,O ���� �ʱ�ȭ
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] == 'X') cnt = 0;
			else if (str[j] == 'O') cnt++;
			result += cnt;
		}
		printf("%d", result);
		if (i < T - 1) printf("\n");
	}

	return 0;
}
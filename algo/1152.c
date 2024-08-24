#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main(void) {
	
	char str[1000001] = { NULL };
	gets(str);
	int cnt = 1;	int i = 0;
	if (str[i] == ' ') cnt--;
	for (i; str[i] != NULL; i++) {
		if (str[i] == ' ') cnt++;
	}	
	if (str[i] == NULL)	if (str[i - 1] == ' ') cnt--;
		
	printf("%d", cnt);
	
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 1000000

int main(void) {
	
	char*word = malloc(sizeof(char)*SIZE);
	int alphabet[26] = { 0 };							//알파벳 갯수

	scanf("%s", word);

	for (int i = 0; word[i] != NULL; i++) {		//word의 size만큼만 반복
		if (word[i] >= 97)word[i] -= ('a' - 'A');	//대문자로 수정
		int order = word[i] - 65;
		alphabet[order]++;
	}
	int max = 0,order;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > max) {
			max = alphabet[i];	order = i;
		}
	}		//max결정
	int cnt = -1;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == max)	cnt++;
	}
	if (cnt == 0)	printf("%c", order + 'A');
	else			printf("?");
	
	free(word);
	return 0;
}

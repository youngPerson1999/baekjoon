#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int groupchk(char*word);				//if word is group word, return 1 or return 0

int main(void) {
	int N, cnt = 0;						//cnt==group word count

	scanf("%d", &N);

	char*word = malloc(sizeof(char) * 100);

	for (int i = 0; i < N; i++) {
		scanf("%s", word);
		if (groupchk(word))	cnt++;
	}

	printf("%d", cnt);

	free(word);
	return 0;
}
int groupchk(char*word) {
	int alphabet[26] = { 0 };
	int first = 1;				//if word's first and rest are all one alphabet, 'first' is 1, or 0
	int conti = 1;				

	for (int i = 0; word[i] != NULL; i++) {
		if (i > 0 && word[i - 1] != word[i] && alphabet[word[i] - 'a'] != 0)	return 0;
		alphabet[word[i] - 'a']++;
	}
	return 1;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int N;
	char *name = malloc(sizeof(char) * 30);
	int alphabet[26] = { 0 };

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", name);
		alphabet[name[0] - 'a']++;
	}
	int max = 0;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > max)max = alphabet[i];
	}
	if (max < 5) {
		printf("PREDAJA");
		free(name);
		return 0;
	}
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == max)	printf("%c", i + 'a');
	}
	free(name);
	return 0;
}

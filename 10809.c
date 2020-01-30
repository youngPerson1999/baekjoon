#include<stdio.h>

int find(char s[],char c);

int main(void) {
	char s[101], i;
	scanf("%s", s);
	for (i = 'a'; i <= 'z'; i++) printf("%d ", find(s,i));
	
	return 0;
}
int find(char s[], char c) {
	int i;
	for (i = 0; s[i]; i++) {
		if (s[i] == c) return i;
	}
	return -1;
}
#include<stdio.h>

int main(void) {
	int arr[8], i, j, check;

	for (i = 0; i < 8; i++) {
		do {
			scanf("%d", &arr[i]);
		} while (arr[i] < 1 || arr[i]>8);
		for (j = 0; j < i; j++) {
			if (arr[j] == arr[i]) i--;
		}
	}
	if (arr[0] == 1) check = 1;
	else if (arr[0] == 8) check = 2;
	else check = 0;
	if (check != 0) {
		for (i = 1; i < 8; i++) {
			if (check == 1) {
				if (arr[i] == i + 1) continue;
				else {
					check = 0;	break;
				}
			}
			else if (check == 2) {
				if (arr[i] == 8 - i) continue;
				else {
					check = 0;	break;
				}
			}
		}
	}
	if (check == 1) printf("ascending");
	else if (check == 2) printf("descending");
	else printf("mixed");
	return 0;
}
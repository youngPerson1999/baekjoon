#include<stdio.h>

int main(void) {
	int mon, day, rst = 0, i;
	do {
		scanf("%d", &mon);
	} while (mon < 1 || mon>12);
	do {
		scanf("%d", &day);
	} while (day < 1 || day>31);

	for (i = 1; i < mon; i++) {
		if (i <= 7 && i % 2) rst += 31;
		else if (i <= 7 && !(i % 2)) {
			if(i!=2)rst += 30;
			else rst += 28;
		}
		else if (i > 7 && i % 2) rst += 30;
		else if (i > 7 && !(i % 2))rst += 31;
	}

	rst += day;
	
	if (rst % 7 == 1) printf("MON");
	else if (rst % 7 == 2) printf("TUE");
	else if (rst % 7 == 3) printf("WED");
	else if (rst % 7 == 4) printf("THU");
	else if (rst % 7 == 5) printf("FRI");
	else if (rst % 7 == 6) printf("SAT");
	else printf("SUN");
	return 0;
}
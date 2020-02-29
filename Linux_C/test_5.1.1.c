//To make this function useful, I change the int to void

#include <stdio.h>

void is_leap_year(int year) {
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		printf("%d is a leap year\n", year);
	else
		printf("%d is not a leap year\n", year);
}

int main(void) {
	is_leap_year(2000);
	is_leap_year(1000);
	is_leap_year(2010);
}

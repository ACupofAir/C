#include <stdio.h>

int hour = 9, minute = 30;
int x = 10;

void print_time(void)
{
	printf("%d:%d in print_time\n",hour,minute);
}

int main(void)
{
	int hour = 11, minute = 30;
	print_time();
	printf("%d:%d in main\n",hour,minute);
	printf("x=%d\n",x);
	return 0;
}

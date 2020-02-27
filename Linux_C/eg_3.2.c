#include <stdio.h>

void newline(void)
{
	printf("\n");
}

void insect_three_newline(void)
{
	newline();
	newline();
	newline();
}

int main(void)
{
	printf("First Line.\n");
	newline();
	insect_three_newline();
	printf("Second Line.\n");
	return 0;
}

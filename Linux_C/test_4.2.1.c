#include <stdio.h>

int main(void)
{
	int x=123;
	int x_divide_ten,x_unit,x_decade;
	x_unit = x % 10;
	x_divide_ten = x / 10;
	x_decade = x_divide_ten % 10;
 // printf("the unit is %d\n",x_unit);
	printf("the decade is %d\n",x_decade);
}

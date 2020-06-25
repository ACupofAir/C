#include <stdio.h>

void print_parity(int x)
{
  if (x % 2 == 0)
    printf("%d is even.\n",x);
  else
	printf("%d is odd.\n",x);
}

int main(void)
{
	print_parity(17);
	print_parity(18);
	return 0;
}

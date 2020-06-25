#include <stdio.h>

int main(void) {
	int n = 1;
	int i = 0;
	while (n < 100) {
		int	n_unit = n % 10;
		int n_decade = n/10;
		if (n_unit ==9) i++;
		if (n_decade ==9) i++;
		n++;
	}
	printf("There are %d 9 from 1 to 100.\n", i);
  return 0;
}

#include <stdio.h>

int main(void) {
	int i,j;
	int k = 0;
	for (i = 1; i <= 100; i++) {
		for (j = 2; j < i; j++) 
		  if (i % j == 0)
				break;
			if (j == i) {
				++k;
				printf("%d\t%d\n", k, i);
		  }
	}
	return 0;
}

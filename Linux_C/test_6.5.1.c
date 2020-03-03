#include <stdio.h>

int main(void) {
	int i,j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= i; j++) //Only need to change the '9' to 'i' 
			printf("%d\t", i*j);
		printf("\n");
	}
	return 0;
}

#include <stdio.h>

int factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; ++i) {
		result = result * i;	
	}
	return result;
}

int main(void) {
	printf("The factorial of 5 is %d\n", factorial(5));
	return 0;
}

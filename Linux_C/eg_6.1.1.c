#include <stdio.h>

int factorial(int n) {
	int result = 1;
	while (n>0) {
		result = result * n;
		n = n - 1;
	} 
	return result;
}

int main(void) {
	printf("The factorial of 10 is %d\n", factorial(10));
return 0;
}

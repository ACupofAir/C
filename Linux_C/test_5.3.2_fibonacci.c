#include <stdio.h>

int fib(int n) {
	if (n == 0 || n == 1)
		return 1;
	else 
		return fib(n-1) + fib(n-2);
}

int main(void) {
	printf("fibonacci's 5 is %d\n", fib(5));
	return 0;
}

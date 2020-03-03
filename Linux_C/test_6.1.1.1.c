#include <stdio.h>

int GetGcd(int a, int b) {
	while (a % b != 0) {
	b = a % b;
	a = b;
	}
	return b;
}

int main(void) {
	printf("The GCD of 100 and 150 is %d.\n", GetGcd(100, 150));
	return 0;
}

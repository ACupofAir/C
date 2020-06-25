#include <stdio.h>

int GetGcd(int a, int b) {
	if (a % b == 0) 
		return b;
	else 
		return GetGcd(b, a % b);
}

int main(void) {
	printf("100 and 150's GCD is %d\n", GetGcd(100,150));
	return 0;
}

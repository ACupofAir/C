#include <stdio.h>
#include <math.h>

void print_logarithm(double x) {
	if (x <= 0.0) {
		printf("Positive numbers only, please.\n");
		return;
	}
	printf("The log of %f is %f\n", x, log(x));
}

int main(void) {
  print_logarithm(-1.0);
  print_logarithm(2.0);
  print_logarithm(10.0);
	return 0;
}

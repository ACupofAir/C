#include <stdio.h>
#include <math.h>

double myround(double x) {
	double x_ceil = ceil(x);
	double x_floor = floor(x);
	if ((x_ceil - x) < (x - x_floor))
		return x_ceil;
	else
		return x_floor;
}

int main(void) {
	printf("In my opinion,-3.51's round is %f\n", myround(-3.51));
	printf("In fact, 3.51's round is %f\n", round(3.51));
	printf("In my opinion, 4.49's round is %f\n", myround(4.49));
	printf("In fact, 4.49's round is %f\n", round(4.49));
}

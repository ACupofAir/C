#include<stdio.h>
#include<math.h>

double distance(double x1, double x2, double y1, double y2) {
	return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}

double circle_area(double radius) {
	return 3.1415926 * radius * radius;
}

int main(void) {
	double radius = distance(1.0, 2.0, 6.0, 4.0);
	printf("Area is %f\n", circle_area(radius));
	return 0;
}

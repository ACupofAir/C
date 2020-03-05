// The code is wrong for the macro define has conflict with the main's 
//declar
#include <stdio.h>
#define RECTANGULAR 1
#define POLAR 2

int main(void) {
	int RECTANGULAR;
	printf("%d %d\n", RECTANGULAR, POLAR);
	return 0;
}

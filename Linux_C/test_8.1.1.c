#include <stdio.h>

int main(void) {
	int a[4] = {1, 2, 3, 4};
	int b[4] = {4, 3, 2, 1};
	int i;
	for (i = 0; i < 4; ++i) 
		printf("%d : %d\n", a[i], b[i]);
	for (i = 0; i < 4; ++i) 
		b[i] = a[i];
	for (i = 0; i < 4; ++i) 
		printf("%d : %d\n", a[i], b[i]);
	return 0;
}

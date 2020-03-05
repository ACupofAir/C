//Only need to figure out the number's space, then add or sub a number
//to make the space in a right place
#include <stdio.h>
#include <stdlib.h>
#define N 20

int a[N];

void gen_random(int upper_bound) {
	int i;
	for (i = 0; i < N; i++)
		a[i] = 10 + rand() % upper_bound;
} 

void print_random() {
	int i;
	for (i = 0; i < N; i++) 
		printf("%d ", a[i]);
	printf("\n");
}

int main(void) {
	gen_random(10);
	print_random();
	return 0;
}

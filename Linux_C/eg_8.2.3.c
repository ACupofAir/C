#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100000

int a[N];

void gen_random(int upper_bound) {
	int i;
	for (i = 0; i < N; i++)
		a[i] = rand() % upper_bound;
} 

int main(void) {
	int i, histogram[10] = {};

	srand(time(NULL));
	gen_random(10);
	for (i = 0; i < N; i++) 
		histogram[a[i]]++;
	for (i = 0; i < 10; i++) 
		printf("%d\t%d\n", i, histogram[i]);
	
	return 0;
}

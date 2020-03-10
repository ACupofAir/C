#include <stdio.h>
#include <assert.h>

#define LEN 8
int a[LEN] = {1, 3, 3, 3, 4, 5, 6, 7};

int is_sorted() {
	int i, sorted = 1;
	for (i = 1; i < LEN; i++)
		sorted *= a[i-1] <= a[i];
	return sorted;
}

int mustbe (int start, int end, int number) {
	int i;
	
	for (i = 0; i < LEN; i++) {
		if (i >= start && i <= end)
			continue;
		if (a[i] == number)
			return 0;
	}
	return 1;
}

int binary_search(int number) {
	int mid, start = 0, end = LEN -1;

	assert(is_sorted());
	while (start <= end) {
		assert(mustbe(start, end, number));
		mid = (start + end) / 2;
		if (a[mid] < number) 
			start = mid + 1;
		else if (a[mid] > number)
			end = mid - 1;
		else 
			return mid;
	}
	assert(mustbe(start, end, number));
	return -1;
}

int main(void) {
	printf("%d\n", binary_search(3));
	return 0;
}

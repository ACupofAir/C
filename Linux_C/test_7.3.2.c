#include <stdio.h>

enum coordinate_type {RECTANGULAR = 1, POLAR};

int main(void) {
//	int RECTANGULAR;
	printf("%d %d\n", RECTANGULAR, POLAR);
	return 0;
}

//这个应该是白纸的覆盖效应,不声明就会是1,但主函数声明后用随机值覆盖了它

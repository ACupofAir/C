#include <stdio.h>

void diamond(int n, char mark) {
	if (n % 2 == 0) {
		printf("Error! I can't do that\n");
	}
	else {
		int i,j;
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j ) {
			  if((((n+1)/2 - i) < j) && (j <((n+1)/2 + i)) && (i <= (n+1)/2))
					printf("%c\t",mark);
				else if(((i - (n+1)/2) < j) && (j <(n+1)*3/2 - i) && (i > (n+1)/2))
					printf("%c\t",mark);
				else 
					printf("\t");
			}
			printf("\n");
		}
	}
}

int main(void) {
	diamond(11, '*');
	diamond(8, '*');
	return 0;
}

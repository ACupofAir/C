#include <stdio.h>
int n = 1;

void get_n(int initNumber) {
  if(initNumber/4 > n*n) return; 
  n++;
  get_n(initNumber*2);
}

int main(void) {
  get_n(2);
  printf("The answer is %d",n);
  return 0;
}

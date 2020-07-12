#include <stdio.h>

int getMatchNum(int n) {
  int num = 0;
  int a[10] = {6,2,5,5,4,5,6,3,7,6};
  while(n/10 != 0) {
    num += a[n%10];
    n = n/10;
  }
  num += a[n];
  return num;
}

int main(void) {
  int A,B;
  int total = 0;
  for(A=0; A<11111; A++) {
    for(B=0; B<11111; B++) {
      if(getMatchNum(A)+getMatchNum(B)+getMatchNum(A+B)==14) {
        printf("%d + %d = %d\n", A,B,A+B);
        total++;
      }
    }
  }
  printf("The number of all functions matched is %d\n", total);
  return 0;
}

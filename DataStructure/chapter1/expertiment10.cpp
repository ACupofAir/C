#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//BinarySearch which is provided by book
int BinarySearch(int *a, const int x, const int n) {
  int left = 0, right = n - 1;
  while(left <= right) {
    int middle = (left+right)/2;
    if(x < a[middle]) right = middle - 1;
    else if (x > a[middle]) left = middle + 1;
    else return middle;
  }
  return -1;
}

int main(void) {
  //Set an array has 100 fixed numbers
  int unsortedNum[100];
  int aimNum;
  srand((unsigned)time(NULL));
  for(int i = 0; i < 100; i++) {
    //unsortedNum[i] = rand()%100;
    unsortedNum[i] = i;
  }

  time_t c_start,c_end;
  for(int n = 0; n < 100; n++) {
    c_start = clock();
    for(int i = 0; i < 10000000; i++) {
      aimNum = rand()%100;
      int tempStore = BinarySearch(unsortedNum, aimNum, n);
      //printf("%d\n", tempStore);
      //printf("%d\n",BinarySearch(unsortedNum, 14, 100));
    }
    c_end = clock();
    printf("n = %d time = %lld\n", n, c_end-c_start);
  }


  return 0;
}

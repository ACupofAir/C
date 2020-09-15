#include <stdio.h>

int city[5][5] = {
  {0,0,0,0,0},
  {0,0,2,6,4},
  {0,999,0,3,999},
  {0,7,999,0,1},
  {0,5,999,12,0}
};

void printCity(int array[][5]) {
  for(int i = 1; i <= 4; i++) {
    for(int j = 1; j <= 4; j++) {
      printf("%d ",array[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  for(int k = 1; k <= 4; k++) {
    for(int i = 1; i <= 4; i++) {
      for(int j = 1; j <= 4; j++) {
        if(city[i][j] > city[i][k] + city[k][j]) {
          city[i][j] = city[i][k] + city[k][j];
        }
      }
    }
    printCity(city);
  }
  return 0;
}

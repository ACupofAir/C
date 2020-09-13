#include <stdio.h>

int city[6][6] = {
  {0,0,0,0,0,0},
  {0,0,2,999,999,10},
  {0,999,0,3,999,7},
  {0,4,999,0,4,999},
  {0,999,999,999,0,5},
  {0,999,999,3,999,0}
};

int book[6] = {0};
int sumStep = 0;

void dfs_city(int step) {
  if(step == 5) {
    printf("%d ", sumStep);
    book[5] = 0;
    return;
  }
  book[step] = 1;
  for(int i = 1; i <= 5; i++) {
    if(book[i]==0 && city[step][i]!=999 && city[step][i]!=0) {
      sumStep += city[step][i];
      book[i] = 1;
      dfs_city(i);
      book[i] = 0;
      sumStep -= city[step][i];
    }
  }
}

int main(void) {
  dfs_city(1);
  return 0;
}

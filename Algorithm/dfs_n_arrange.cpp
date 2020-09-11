#include <iostream>
#include <stdio.h>
#define N 3

int book[N+1] = {0};
int box[N+1] = {0};

using namespace std;

void dfs_n_arrange (int step) {
  if(step==N+1) {
    for(int i = 1; i <= N; i++) {
      printf("box[%d]=%d\n",i,box[i]);
    }
    return;
  }
  for(int i = 1; i <= N; i++) {
    if(book[i] == 0) {
      box[step] = i;
      book[i] = 1;
      dfs_n_arrange(step+1);
      book[i] = 0;
    }
  }
}

int main(void) {
  dfs_n_arrange(1);
  return 0;
}

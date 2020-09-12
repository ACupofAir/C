#include <stdio.h>

int graph[6][6] = {
  {0,1,1,2,1},
  {1,0,2,1,2},
  {1,2,0,2,1},
  {2,1,2,0,2},
  {1,2,1,2,0}
};

int sum = 0;
int book[6] = {0};

void dfs_graph_five(int step) {
  sum++;
  if(sum == 5) return;
  printf("%d ",step);
  book[step] = 1;

  for(int i = 1; i <= 5; i++) {
    if(book[i]==0 && graph[step-1][i-1]==1) {
      dfs_graph_five(i);
    }
  }
  return;
}

int main(void) {
  dfs_graph_five(1);
  return 0;
}

#include <stdio.h>

int graph[6][6] = {
  {0,0,0,0,0,0},
  {0,0,1,1,2,1},
  {0,1,0,2,1,2},
  {0,1,2,0,2,1},
  {0,2,1,2,0,2},
  {0,1,2,1,2,0}
};

int book[6] = {0};
int que[6] = {1,1};//make the que[1] = 1
int head = 1;
int tail = 1;

void bfs_five_five(int step) {
  if(tail == 5) return;
  for(int i = 1; i <=5; i++) {
    if(graph[step][i]==1 && book[i]==0) {
      book[i] = 1;
      tail++;
      que[tail] = i;
    }
  }
  head++;
  bfs_five_five(que[head]);
}

int main(void) {
  book[1] = 1;
  bfs_five_five(1);
  for(int i = 1; i <=5; i++) {
    printf("%d ",que[i]);
  }
  return 0;
}

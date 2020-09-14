#include <stdio.h>

int graph[6][6] = {
  {0,0,0,0,0,0},
  {0,0,1,1,0,0},
  {0,1,0,1,1,0},
  {0,1,1,0,1,1},
  {0,0,1,1,0,1},
  {0,0,0,1,1,0}
};

class Node {
  public :
    int location;
    int step;
};

int book[6] = {0};
Node queue[6];
int head = 1;
int tail = 1;
int step = 0;

void bfs_graph_traverse(int currentLocation) {
  if(currentLocation==5) return;
  for(int i = 1; i <=5; i++) {
    if(graph[currentLocation][i]==1 && book[i]==0) {
      book[i] = 1;
      tail++;
      queue[tail].location = i;
      queue[tail].step = queue[currentLocation].step + 1;
    }
  }
  head++;
  bfs_graph_traverse(queue[head].location);
  //return;
}

int main(void) {
  //init the first step
  queue[1].location = 1;
  queue[1].step = 0;
  book[1] = 1;

  bfs_graph_traverse(1);
  printf("Without return is ok\n");
  for(int i = 1; i <= 5; i++) {
    printf("queue[%d] = %d\n",queue[i].location,queue[i].step);
  }
  return 0;
}

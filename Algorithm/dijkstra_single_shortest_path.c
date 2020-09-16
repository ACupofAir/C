#include <stdio.h>

int city[7][7] = {
  {0 ,0 ,0 ,0 ,0 ,0 ,0 },
  {0 ,0 ,1 ,12,99,99,99},
  {0 ,99,0 , 9, 3,99,99},
  {0 ,99,99, 0,99,5 ,99},
  {0 ,99,99, 4, 0,13,15},
  {0 ,99,99,99,99,0 , 4},
  {0 ,99,99,99,99,99, 0}
};
int book[7] = {0};

//find next cur
int find_next_cur(int a[7]) {
  int temp_min = 999;
  int temp_min_i = 0;
  for(int i = 0; i <= 6; i++) {
    if(a[i] < temp_min && book[i] != 1) {
      temp_min = a[i];
      temp_min_i = i;
    }
  }
  return temp_min_i;
}

int dis[7] = {0,0,1,12,99,99,99};

void dijkstra(int cur) {
  if(book[1]*book[2]*book[3]*book[4]*book[5]*book[6] != 0) return;
  book[cur] = 1;
  //Firstly update distance
  for(int i = 1; i <= 6; i++) {
    if(city[cur][i]!=99 && city[cur][i]!=0 && (city[cur][i]+dis[cur])<dis[i]) {
      dis[i] = city[cur][i] + dis[cur];
    }
  }

  //Now find the next cur
  //Details to see the funcation of find_next_cur
  printf("%d \n",cur);
  for(int i = 1; i <= 6; i++) {
    printf("%d ", dis[i]);
  }
  printf("\n");
  dijkstra(find_next_cur(dis));
}

int main(void) {
  dijkstra(1);
  for(int i = 1; i <= 6; i++) {
    printf("%d ", dis[i]);
  }
  return 0;
}

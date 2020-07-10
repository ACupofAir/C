#include <stdio.h>
int p,q;
int min = 1000;
int m,n;
int a[50][50];
int book[50][50];

void dfs(int x, int y, int step) {
  if(x==p && y==q) {
    if(step < min) {
      min = step;
    }
    return;
  }

  int tx,ty;
  int next[4][2] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0},
  };
  for(int k=0; k < 4; k++) {
    tx = x + next[k][0];
    ty = y + next[k][1];

    if(tx < 1 || tx > n || ty < 1 || ty >n) {
      continue;
    }

    if(a[tx][ty] == 0 && book[tx][ty] == 0) {
      book[tx][ty] = 1;
      dfs(tx,ty,step+1);
      book[tx][ty] = 0;
    }
  }

  return;
}

int main(void) {
  int row,col;
  int **map = new *int[row];
}

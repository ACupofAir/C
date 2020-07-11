#include <stdio.h>
int p,q;
int min = 1000;
int m,n;
int map[50][50];
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

    if(tx < 1 || tx > n || ty < 1 || ty > m) {
      continue;
    }

    if(map[tx][ty] == 0 && book[tx][ty] == 0) {
      book[tx][ty] = 1;
      dfs(tx,ty,step+1);
      book[tx][ty] = 0;
    }
  }

  return;
}

int main(void) {
  printf("Set the map's size: row\n");
  scanf("%d",&n);
  printf("Set the map's size: col\n");
  scanf("%d",&m);

  for(int i=1; i <= n; i++) {
    for(int j=1; j <= m; j++) {
      printf("%d : \n ",i);
      scanf("%d",&map[i][j]);
    }
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      printf("%d ",map[i][j]);
    }
    printf("\n");
  }

  int startx, starty;
  printf("Set the first coordinate: \n");
  scanf("%d %d", &startx, &starty);

  printf("Set the end coordinate: \n");
  scanf("%d %d", &p, &q);

  book[startx][starty] = 1;
  dfs(startx,starty,0);
  printf("%d",min);

  return 0;
}

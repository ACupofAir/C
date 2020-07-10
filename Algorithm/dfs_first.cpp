#include  <stdio.h>

int box[10] = {0};
int book[10] = {0};

void dfs(int step, int n) {
  int i;
  if(step==n+1) {
    for(i=1; i<=n; i++) {
      printf("%d", box[i]);
    }
    printf("\n");
    return;
  }

  for(i=1; i<=n; i++) {
    if(book[i]==0) {
      box[step] = i;
      book[i] = 1;

      dfs(step+1, n);
      book[i] = 0;
    }
  }

  return;
}

int main(void) {
  dfs(1,9);
  return 0;
}

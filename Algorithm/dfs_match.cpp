#include <stdio.h>

int box[10], book[10], total = 0;
void dfs(int step) {
  int i;
  if(step == 10) {
    if(box[1]*100+box[2]*10+box[3]+box[4]*100+box[5]*10+box[6]==box[7]*100+box[8]*10+box[9]) {
      total++;
      printf("%d%d%d + %d%d%d = %d%d%d\n", box[1],box[2],box[3],box[4],box[5],box[6],box[7],box[8],box[9]);
    }
    return;
  }

  for(i=1; i<=9; i++) {
    if(book[i]==0) {
      box[step] = i;
      book[i] = 1;

      dfs(step+1);
      book[i] = 0; //for return to here, we must book it to zero again.
    }
  }

  return;
}

int main(void) {
  dfs(1);

  printf("Total=%d\n",total/2);

  return 0;
}

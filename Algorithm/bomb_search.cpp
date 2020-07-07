#include <iostream>
#include <stdio.h>

using namespace std;

int main(void) {
  int row, col;  
  cout<<"Set the map's row number: \n";
  cin>>row;
  cout<<"Set the map's col number: \n";
  cin>>col;
  char **map = new char *[row]; 
  for(int i = 0; i < col; i++) {
    map[i] = new char[col];
  }
  cout<<"Set your map's object: \n";
  for (int i = 0; i < row; i++) {
    cout<<"Set "<<i+1<<" row"<<endl;
    cin>>map[i]; 
  }
  cout<<"Your map's object is: \n";
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout<<map[i][j];
    }
    cout<<endl;
  }

  int sum,sumMax;
  sumMax = 0;
  int x,y;
  int xMax, yMax;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (map[i][j]=='.') {
        //printf("%d,%d ",i,j);
        sum = 0;

        x = i; y = j;
        while(map[x][y] != '#') {
          //up:
          if(map[x][y] == 'G') {
            sum++;
          }
          x--;
        }

        x = i; y = j;
        while(map[x][y] != '#') {
          //down:
          if(map[x][y] == 'G') {
            sum++;
          }
          x++;
        }

        x = i; y = j;
        while(map[x][y] != '#') {
          //ringht:
          if(map[x][y] == 'G') {
            sum++;
          }
          y++;
        }

        x = i; y = j;
        while(map[x][y] != '#') {
          //left:
          if(map[x][y] == 'G') {
            sum++;
          }
          y--;
        }
      }

      if (sum > sumMax) {
        printf("%d,%d ",i,j);
        sumMax = sum;
        xMax = i;
        yMax = j;
      }
    }
  }

  printf("Put the bomb at (%d, %d), and the max number of enemy which is destoryed is %d\n", xMax, yMax, sumMax);
  return 0;
}

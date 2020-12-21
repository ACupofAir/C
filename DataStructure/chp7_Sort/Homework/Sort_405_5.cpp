#include <iostream>
#include <utility>
#include "QuickSort.h"

using namespace std;

int main(void)
{
  pair<int, int> arr[3];
  arr[0] = pair<int,int>(2,3);
  arr[1] = pair<int,int>(2,1);
  arr[2] = pair<int,int>(1,6);
  arr[3] = pair<int,int>(3,7);
  quickSort(arr, 0, 3);
  for(int i = 0; i < 4; i++)
  {
    cout<<"<"<<arr[i].first<<","<<arr[i].second<<">"<<endl;
  }
  return 0;
}
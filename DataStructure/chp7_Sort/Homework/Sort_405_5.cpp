#include <iostream>
#include "QuickSort.h"
#include "Pair.h"

using namespace std;

int main(void)
{
  Pair<int, int> arr[4];
  arr[0] = Pair<int,int>(1,3);
  arr[1] = Pair<int,int>(2,1);
  arr[2] = Pair<int,int>(1,6);
  arr[3] = Pair<int,int>(3,7);
  quickSort(arr, 0, 3);
  for(int i = 0; i < 4; i++)
  {
    cout<<"<"<<arr[i].first()<<","<<arr[i].second()<<">"<<endl;
  }
  return 0;
}
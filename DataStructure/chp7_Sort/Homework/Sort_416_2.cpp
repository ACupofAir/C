#include <iostream>
#include "HeapSort.h"

using namespace std;

int main(void)
{
  pair<int, int> arr[7];
  arr[1] = pair<int,int>(2,1);
  arr[2] = pair<int,int>(1,2);
  arr[3] = pair<int,int>(3,6);
  arr[4] = pair<int,int>(3,3);
  arr[5] = pair<int,int>(3,4);
  arr[6] = pair<int,int>(6,5);
  HeapSort(arr, 6);
  for(int i = 1; i <= 6; i++)
  {
    cout<<"<"<<arr[i].first<<","<<arr[i].second<<">"<<endl;
  }
  return 0;
}
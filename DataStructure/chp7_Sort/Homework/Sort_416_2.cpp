#include <iostream>
#include "HeapSort.h"
#include "Pair.h"

using namespace std;

int main(void)
{
  Pair<int, int> arr[7];
  arr[1] = Pair<int,int>(2,1);
  arr[2] = Pair<int,int>(1,2);
  arr[3] = Pair<int,int>(3,6);
  arr[4] = Pair<int,int>(3,3);
  arr[5] = Pair<int,int>(3,4);
  arr[6] = Pair<int,int>(6,5);
  HeapSort(arr, 6);
  for(int i = 1; i <= 6; i++)
  {
    cout<<"<"<<arr[i].first()<<","<<arr[i].second()<<">"<<endl;
  }
  return 0;
}
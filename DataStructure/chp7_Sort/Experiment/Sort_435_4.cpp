#include <iostream>
#include <windows.h>
#include "InsertSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "QuickSort.h"

using namespace std;

double getTestTime(int n, void (*sortFunc)(int *arr, int n), int *(*generateSortArr)(int n))
{
  int *arr = generateSortArr(n);
  long long time;
  LARGE_INTEGER t1, t2, tc;
  QueryPerformanceFrequency(&tc);
  QueryPerformanceCounter(&t1);
  for (int i = 0; i < 100; i++)
  {
    sortFunc(arr, n);
  }
  QueryPerformanceCounter(&t2);
  return (double)(t2.QuadPart - t1.QuadPart)/100;
}

int main(void)
{
  int n = 10;
  cout << getTestTime(n, InsertSort<int>, generateInsertSortArr)<<endl;
  cout << getTestTime(n, MergeSort<int>, generateMergeSortArr)<<endl;
  cout << getTestTime(n, HeapSort<int>, generateHeapSortArr)<<endl;
  cout << getTestTime(n, quickSort<int>, generateQuickSortArr)<<endl;
}
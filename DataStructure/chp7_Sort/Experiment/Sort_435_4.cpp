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
  for (int i = 0; i < 10; i++)
  {
    sortFunc(arr, n);
  }
  QueryPerformanceCounter(&t2);
  return (double)(t2.QuadPart - t1.QuadPart)/10;
}

void mixSort(int* arr, int n)
{
  if (n < 300)
  {
    InsertSort(arr, n);
  }
  else
  {
    MergeSort(arr, n);
  }
}

int main(void)
{
  int arr[7] = {100, 500, 1000, 2000, 4000, 8000, 16000};

  cout<<"n"<<"\t\tInsert"<<"\t\tMerge"<<"\t\tHeap"<<"\t\tQuick"<<"\t\tMix\n";
  for (int i = 0; i < 7; i++)
  {
    cout << arr[i] << "\t\t";
    cout << getTestTime(arr[i], InsertSort<int>, generateInsertSortArr) << "\t\t";
    cout << getTestTime(arr[i], MergeSort<int>, generateMergeSortArr) << "\t\t";
    cout << getTestTime(arr[i], HeapSort<int>, generateHeapSortArr) << "\t\t";
    cout << getTestTime(arr[i], quickSort<int>, generateQuickSortArr) << "\t\t";
    cout << getTestTime(arr[i], mixSort, generateQuickSortArr) << "\n";
  }
  return 0;
}
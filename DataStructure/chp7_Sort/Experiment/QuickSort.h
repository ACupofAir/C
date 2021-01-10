#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <windows.h>
#include "Swap.h"


template <class T>
void quickSort(T *arr, const int left, const int right)
{
  if(left<right)
  {
    //Init pivot
    T pivot = arr[left];

    //Init two guards:
    int i = left;
    int j = right + 1;

    do
    {
      do
        i++;
      while (arr[i] < pivot);
      do
        j--;
      while (arr[j] > pivot);
      if (i < j)
        swap(arr[i], arr[j]);
    } while (i < j);

      //Swap arr[i], arr[j]
    swap(arr[left], arr[j]);
    quickSort(arr, left, j-1);
    quickSort(arr, j+1, right);
  }
}


template <class T>
void quickSort(T *arr, const int n)
{
  quickSort<T>(arr, 1, n);
}

int *generateQuickSortArr(int n)
{
  int *wosrtArr = nullptr;
  long long longestTime = -1;

  for (int i = 0; i < 100; i++)
  {
    int *arr = new int[n + 1];
    int *bak = new int[n + 1];

    for (int i = 1; i <= n; i++)
      arr[i] = i;
    for (int i = n; i >= 2; i--)
    {
      int j = rand() % i + 1;
      swap(arr[j], arr[i]);
    }
    memcpy(bak, arr, sizeof(int) * (n + 1));

    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    quickSort<int>(arr, n);
    QueryPerformanceCounter(&t2);

    if (longestTime < t2.QuadPart - t1.QuadPart)
    {
      longestTime = t2.QuadPart - t1.QuadPart;
      if (wosrtArr != nullptr)
        delete[] wosrtArr;
      wosrtArr = bak;
      delete[] arr;
    }
    else
    {
      delete[] arr;
      delete[] bak;
    }
    return wosrtArr;
  }
}
#endif
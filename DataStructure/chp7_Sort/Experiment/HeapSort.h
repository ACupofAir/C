#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <windows.h>
#include "Swap.h"


template <class T>
void Adjust(T *a, const int root, const int n)
{
  T e = a[root];
  int j;
  for (j = 2 * root; j <= n; j *= 2)
  {
    if (j < n && a[j] < a[j + 1])
      j++;
    if (e >= a[j])
      break;
    a[j / 2] = a[j];
  }
  a[j / 2] = e;
}

template <class T>
void HeapSort(T *a, const int n)
{
  for (int i = n / 2; i >= 1; i--)
    Adjust(a, i, n);
  for (int i = n - 1; i >= 1; i--)
  {
    swap(a[1], a[i + 1]);
    Adjust(a, 1, i);
  }
}

int *generateHeapSortArr(int n)
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
    HeapSort<int>(arr, n);
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
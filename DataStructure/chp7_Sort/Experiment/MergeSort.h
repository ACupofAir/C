#ifndef MERGESORT_H
#define MERGESORT_H

#include <cmath>

template <class T>
void copy(const T *begin, const T *end, T *dest)
{
  for(const T *i = begin; i != end; i++, dest++)
  {
    *dest = *i;
  }
}

template <class T>
void Merge(T *intitList, T *mergedList, const int l, const int m, const int n)
{
  int i1 = l; int iResult = l; int i2 = m + 1;
  for (; i1 <= m && i2 <= n; iResult++)
  {
    if (intitList[i1] <= intitList[i2])
    {
      mergedList[iResult] = intitList[i1];
      i1++;
    }
    else
    {
      mergedList[iResult] = intitList[i2];
      i2++;
    }
  }
  copy(intitList + i1, intitList + m + 1, mergedList + iResult);
  copy(intitList + i2, intitList + n + 1, mergedList + iResult);
}

template <class T>
void MergePass(T *initList, T *resultList, const int n, const int s)
{
  int i;
  for (i = 1; i < n - 2 * s + 1; i += 2 * s)
  {
    Merge(initList, resultList, i, i + s - 1, i + 2 * s - 1);
  }
  if ((i + s - 1) < n)
    Merge(initList, resultList, i, i + s - 1, n);
  else
    copy(initList + i, initList + n + 1, resultList + i);
}

template <class T>
void MergeSort(T *a, const int n)
{
  T* tempList = new T[n+1];
  for (int l = 1; l < n; l *= 2)
  {
    MergePass(a, tempList, n, l);
    l *= 2;
    MergePass(tempList, a, n, l);
  }
  delete [] tempList;
}

void generateMergeSortArr(int *arr, int left, int right)
{
  if (right - left == 0)
    return;

  int *temp = new int[right - left + 1];
  int mid = left + pow(2, (int)(log(right - left) / log(2))) - 1;
  if(mid == right)
    mid = (left+right)/2;

  int index = left, i, j;
  for(i = left, j = mid + 1; i <= mid && j <= right; i++, j++)
  {
    temp[i - left] = arr[index++];
    temp[j - left] = arr[index++];
  }
  while(i <= mid)
  {
    temp[i-left] = arr[index++];
    i++;
  }
  while(j <= mid)
  {
    temp[j-left] = arr[index++];
    j++;
  }
  for (int i = left; i <= right; i++)
  {
    arr[i] = temp[i - left];
  }
  delete[] temp;

  generateMergeSortArr(arr, left, mid);
  generateMergeSortArr(arr, mid + 1, right);
}

int *generateMergeSortArr(int n)
{
  int *worstArr = new int[n + 1];
  for (int i = 1; i <= n; i++)
  {
    worstArr[i] = i;
  }
  generateMergeSortArr(worstArr, 1, n);
  return worstArr;
}

#endif
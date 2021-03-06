#ifndef INSERTSORT_H
#define INSERTSORT_H

template <class T>
void Insert(const T &e, T *a, int i)
{
  a[0] = e;
  while (a[i] > a[0])
  {
    a[i + 1] = a[i];
    i--;
  }
  a[i + 1] = e;
}

template <class T>
void InsertSort(T *a, const int n)
{
  for(int i = 2; i <= n; i++)
  {
    T temp = a[i];
    Insert(temp, a, i-1);
  }
}

int* generateInsertSortArr(int n)
{
  int* worstArr = new int[n+1];
  for(int i = 1; i <= n; i++)
  {
    worstArr[i] = n-i+1;
  }
  return worstArr;
}

#endif
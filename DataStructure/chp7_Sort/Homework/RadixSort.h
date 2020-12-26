#ifndef RADIXSORT_H
#define RADIXSORT_H
#include <cmath>

//Return r_radix number's digit i(which sorts from 0)
int digit(int& value, int i, int r)
{
  return (int)(value / pow(r, i)) % r;
}

template <class T>
int RadixSort(T *a, int *link, const int d, const int r, const int n)
{
  int e[r], f[r];
  int first = 1;
  int i;
  for (i = 1; i < n; i++)
  {
    link[i] = i + 1;
  }
  link[n] = 0;
  for (i = d - 1; i >= 0; i--)
  {
    int j;
    for (j = 0; j < r; j++)
      f[j] = 0;
    for (int current = first; current; current = link[current])
    {
      int k = digit(a[current], (d-1-i), r);
      if (f[k] == 0)
        f[k] = current;
      else
        link[e[k]] = current;
      e[k] = current;
    }
    for (j = 0; !f[j]; j++)
      ;
    first = f[j];
    int last = e[j];
    for (int k = j + 1; k < r; k++)
      if (f[k])
      {
        link[last] = f[k];
        last = e[k];
      }
    link[last] = 0;
  }
  return first;
}

#endif
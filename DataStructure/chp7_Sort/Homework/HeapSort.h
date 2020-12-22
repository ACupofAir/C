#ifndef HEAPSORT_H
#define HEAPSORT_H

template <class T>
void swap(T &a, T &b)
{
  T temp = a;
  a = b;
  b = temp;
}

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

#endif
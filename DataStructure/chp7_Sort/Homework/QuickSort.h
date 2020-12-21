#ifndef QUICKSORT_H
#define QUICKSORT_H

template<class T>
void swap(T& a, T& b)
{
  T temp = a;
  a = b;
  b = temp;
}

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

#endif
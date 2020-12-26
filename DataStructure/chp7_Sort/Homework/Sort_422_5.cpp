#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "RadixSort.h"

using namespace std;

int main(void)
{
  int n;
  cout << "Input n: \n";
  cin >> n;
  srand((unsigned)time(NULL));
  int *arr = new int[n + 1];
  for (int i = 1; i <= n; i++)
  {
    arr[i] = rand() % (n * n);
  }

  cout << "Before sort:\n";
  for (int i = 1; i <= n; i++)
  {
    cout << arr[i] << "\t\t";
  }
  cout<<endl;

  int *link = new int[n + 1];
  int first = RadixSort(arr, link, 2, n, n);

  cout << "After sort:\n";
  for (int i = first; i; i = link[i])
  {
    cout << arr[i] << "\t\t";
  }
  return 0;
}
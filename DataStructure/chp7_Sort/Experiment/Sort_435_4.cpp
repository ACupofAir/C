#include <iostream>
#include "InsertSort.h"
#include "Pair.h"

using namespace std;

int main(void)
{
  cout<<"Input the num of sort elements\n";
  int n;
  cin>>n;
  Pair<int, int> *a = new Pair<int, int>[n+1];
  for(int i = 1; i <= n; i++)
  {
    a[i] =  Pair<int, int>(rand(), rand());
  }

  cout << "Before sort:" << endl;
  for(int i = 1; i <= n; i++)
  {
    cout<<"<"<<a[i].first()<<","<<a[i].second()<<">"<<endl;
  }

  InsertSort(a, n);
  cout << "After sort:" << endl;
  for(int i = 1; i <= n; i++)
  {
    cout<<"<"<<a[i].first()<<","<<a[i].second()<<">"<<endl;
  }
  return 0;
}
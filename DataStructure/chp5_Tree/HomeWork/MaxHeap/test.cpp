#include <iostream>
#include <vector>   
using namespace std;
int main(void)      
{                   
  int num = 5;        
  int* arr = new int[num];
  vector<int> vec(num);  
  cout<<vec.capacity()<<endl;     
  cout<<vec.size()<<endl;     
  for(int i = 0; i < num; i++)
  {                           
    arr[i] = i;               
    vec[i] = i;               
  }                           
  vec.reserve(10);            
  cout<<vec.size()<<endl;     
  vec.push_back(6);
  vec[8] = 6;                 
  cout<<vec.size()<<endl;     
  cout<<vec.capacity()<<endl;     
  return 0;                   
}                             
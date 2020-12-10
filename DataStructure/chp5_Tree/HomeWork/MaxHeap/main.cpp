#include "MaxHeap.h"
#include <stdlib.h>                                         
#include <time.h>                                           
#include <windows.h>                                        
#include <iostream>                                         
using namespace std;                                        
                                                            
                                                            
void getNElementsHeapTimeNormal(int n)                      
{                                                           
  LARGE_INTEGER t1, t2, tc;                                 
  QueryPerformanceFrequency(&tc);                           
  MaxHeap<int> testHeap;                                    
                                                            
  srand((unsigned)time(NULL));                              
  for(int i = 0; i < n; i++)                                
  {                                                                
    testHeap.Push(rand());                                         
  }                                                                
                                                                   
  QueryPerformanceCounter(&t1);                                     
  for(int i = 0; i < 1000; i++)                                    
  {                                                                  
    testHeap.Push(rand());                                           
  }                                                                  
  QueryPerformanceCounter(&t2);                                     
  cout<<n<<" \t\t "<<(t2.QuadPart-t1.QuadPart)<<"us\n";     
}                                                                    
                                                                     
                                                                     
int main(void)                                                       
{                                                                    
  getNElementsHeapTimeNormal(100);                                      
  getNElementsHeapTimeNormal(500);                                      
  getNElementsHeapTimeNormal(1000);                                      
  getNElementsHeapTimeNormal(100000);                                      
  getNElementsHeapTimeNormal(2000);                                      
  getNElementsHeapTimeNormal(3000);                                      
  getNElementsHeapTimeNormal(4000);                                      
  return 0;                                                          
}                                                                    
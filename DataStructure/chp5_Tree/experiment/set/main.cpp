#include "Set.h"
#include <ctime>                                                                                
#include <iostream>                                                                             
using namespace std;                                                                            
                                                                                                
void test(const char *name, void (Sets::*unionFunc)(int i, int j), int (Sets::*findFunc)(int i))
{                                                                                               
  int testNum = 1000000;                                                                        
  int* testArr = new int[testNum];                                                              
  for(int i = 0; i < testNum; i++)                                                              
  {                                                                                             
    testArr[i] = rand()%2000;                                                                   
  }                                                                                             
                                                                                                
  Sets testSets(2000);                                                                          
  time_t begin, end;                                                                            
  begin = clock();                                                                              
  for(int i = 0; i < testNum/2; i++)                                                            
  {                                                                                             
    int p1 = (testSets.*findFunc)(testArr[2*i]);                                                
    int p2 = (testSets.*findFunc)(testArr[2*i+1]);                                                
    if(p1!=p2)                                                                                  
    {                                                                                           
      (testSets.*unionFunc)(p1,p2);                                                             
    }                                                                                           
  }                                                                                             
  end = clock();                                                                                
  cout<<name<<" use " << (end-begin) <<"ms" << endl;                                            
}                                                                                               
                                                                                                
int main(void)                                                                                  
{                                                                                               
  test("SimpleUnion + Simple Find", &Sets::SimpleUnion, &Sets::SimpleFind);                     
  test("SimpleUnion + CollapsingFind", &Sets::SimpleUnion, &Sets::CollapsingFind);              
  test("WeightUnion + Simple Find", &Sets::WeightdUnion, &Sets::SimpleFind);                    
  test("WeigtUnion + CollapsingFind Find", &Sets::WeightdUnion, &Sets::CollapsingFind);           
  return 0;                                                                                     
}                                                                                               
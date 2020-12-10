#include <iostream>
#include <vector>                
#include <time.h>                  
#include <stdlib.h>                     
#include <windows.h>                                        
                                        
using namespace std;                    
                                        
void getBuildLoseTreeTime(int k)        
{                                
  LARGE_INTEGER t1, t2, tc;                                 
  QueryPerformanceFrequency(&tc);                           
  vector<int> LoseTree(2*k);            
  srand((unsigned)time(NULL));          
  for(int i = k; i < 2*k; i++)          
  {                                     
    LoseTree[i] = rand();               
  }                                     
                                        
  //Build WinnerTree                    
  QueryPerformanceCounter(&t1);                                     
  for(int i = k-1; i > 0; i--)          
  {                                     
    if(LoseTree[2*i] < LoseTree[2*i+1]) 
    {                                   
      LoseTree[i] = LoseTree[2*i];      
    }                                   
    else                                
    {                                           
      LoseTree[i] = LoseTree[2*i+1];            
    }                                           
  }                                              
                                                 
  LoseTree[0] = LoseTree[1];                     
                                                 
  //Build LoseTree from WinnerTree                 
  for(int i = 1; i < k; i++)                       
  {                                                
    if(LoseTree[i] == LoseTree[2*i])               
    {                                              
      LoseTree[i] = LoseTree[2*i+1];               
    }                                              
    else                                           
    {                                              
      LoseTree[i] = LoseTree[2*i];                 
    }                                              
  }                                                
  QueryPerformanceCounter(&t2);                                     
  cout<<k<<" \t\t "<<(t2.QuadPart-t1.QuadPart)<<"us\n";     
}                                                  
                                                   
int main(void)                                     
{                                                  
  int k = 5;                                       
  vector<int> LoseTree(2*k);                       
  srand((unsigned)time(NULL));                     
  for(int i = k; i < 2*k; i++)                     
  {                                                
    LoseTree[i] = rand();                          
  }                                                
                                                   
  //Build WinnerTree                               
  for(int i = k-1; i > 0; i--)                     
  {                                                
    if(LoseTree[2*i] < LoseTree[2*i+1])            
    {                                              
      LoseTree[i] = LoseTree[2*i];                 
    }                                              
    else                                           
    {                                              
      LoseTree[i] = LoseTree[2*i+1];               
    }                                              
  }                                                
                                                   
  LoseTree[0] = LoseTree[1];                       
                                                   
  //Build LoseTree from WinnerTree                 
  for(int i = 1; i < k; i++)                       
  {                                                
    if(LoseTree[i] == LoseTree[2*i])               
    {                                              
      LoseTree[i] = LoseTree[2*i+1];               
    }                                              
    else                                           
    {                                              
      LoseTree[i] = LoseTree[2*i];                 
    }                                              
  }                                                
                                                   
  for(int i = 0; i < 2*k; i++)                     
  {                                                
    cout<<"LoseTree["<<i<<"] :"<<LoseTree[i]<<endl;
  }                                                
  getBuildLoseTreeTime(1000);                      
  getBuildLoseTreeTime(2000);                      
  getBuildLoseTreeTime(3000);                      
  getBuildLoseTreeTime(4000);                      
  getBuildLoseTreeTime(5000);                      
  getBuildLoseTreeTime(6000);                      
  getBuildLoseTreeTime(7000);                      
  getBuildLoseTreeTime(8000);                      
  getBuildLoseTreeTime(9000);                      
  getBuildLoseTreeTime(10000);                     
  return 0;                                        
}                                                  
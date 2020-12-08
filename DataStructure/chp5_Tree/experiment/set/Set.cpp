#include "Set.h"
Sets::Sets(int numberOfElements)                       
{                                                      
  if (numberOfElements < 2)                            
    throw "Must have at least 2 elements";             
  this->n = numberOfElements;                          
  this->parent = new int[this->n];                     
  fill(this->parent, this->parent + n, -1);            
}                                                      
                                                                                
void Sets::fill(int *begin, int *end, int value)                                
{                                                                               
  int* p = begin;                                                               
  while(p != end) {                                                             
    *p = value;                                                                 
    p++;                                                                        
  }                                                                             
}                                                                               
                                                                                
void Sets::SimpleUnion(int i, int j)                                            
{                                                                               
  parent[i] = j;                                                                
}                                                                               
                                                                                
int Sets::SimpleFind(int i)                                                     
{                                                                               
  while(parent[i] > 0) {                                                                
    i = parent[i];                                                                      
  }                                                                                     
  return i;                                                                             
}                                                                                       
                                                                                        
void Sets::WeightdUnion(int i, int j)                                                   
{                                                                                       
  int temp = parent[i] + parent[j];                                                     
  if(parent[i] > parent[j]) {                                                           
    parent[i] = j;                                                                      
    parent[j] = temp;                                                                   
  }                                                                                     
  else                                                                                  
  {                                                                                     
    parent[j] = i;                                                                      
    parent[i] = temp;                                                                   
  }                                                                                     
}                                                                                       
                                                                                        
int Sets::CollapsingFind(int i)                                                         
{                                                                                       
  int r;                                                                                
  for (r = i; parent[r] > 0; r = parent[r]);                                            
  while (i != r)                                                                        
  {                                                                                     
    int s = parent[i];                                                                  
    parent[i] = r;                                                                      
    i = s;                                                                              
  }                                                                                     
  return r;                                                                             
}                                                                                       
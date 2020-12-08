#include "BST.h"
#include <stdlib.h>                                                                                       
#include <time.h>                                                                                                
#include <cmath>                                                                                                 
                                                                                                                 
int getTestHeight(int numOfElements)                                                                             
{                                                                                                                
  BST<int, int> testBST;                                                                                         
  srand((unsigned)time(NULL));                                                                                   
  int ranNum;                                                                                                    
  for(int i = 0; i < numOfElements; i++)                                                                         
  {                                                                                                                  
    ranNum = rand();                                                                                                 
    testBST.Insert(pair<int,int>(ranNum,ranNum));                                                                    
  }                                                                                                                  
  return testBST.getHeight(testBST.root);                                                                            
}                                                                                                                    
                                                                                                                     
int main(void)                                                                                                       
{                                                                                                                    
  cout<<"n:100"<<"\t\tHeight:"<<getTestHeight(100)<<"\tHeight/Log2N:"<<getTestHeight(100)/log2(100)<<endl;           
  cout<<"n:500"<<"\t\tHeight:"<<getTestHeight(500)<<"\tHeight/Log2N:"<<getTestHeight(500)/log2(500)<<endl;           
  cout<<"n:1000"<<"\t\tHeight:"<<getTestHeight(1000)<<"\tHeight/Log2N:"<<getTestHeight(1000)/log2(1000)<<endl;       
  cout<<"n:2000"<<"\t\tHeight:"<<getTestHeight(2000)<<"\tHeight/Log2N:"<<getTestHeight(2000)/log2(2000)<<endl;       
  cout<<"n:3000"<<"\t\tHeight:"<<getTestHeight(3000)<<"\tHeight/Log2N:"<<getTestHeight(3000)/log2(3000)<<endl;       
  cout<<"n:4000"<<"\t\tHeight:"<<getTestHeight(4000)<<"\tHeight/Log2N:"<<getTestHeight(4000)/log2(4000)<<endl;       
  cout<<"n:5000"<<"\t\tHeight:"<<getTestHeight(5000)<<"\tHeight/Log2N:"<<getTestHeight(5000)/log2(5000)<<endl;       
  cout<<"n:6000"<<"\t\tHeight:"<<getTestHeight(6000)<<"\tHeight/Log2N:"<<getTestHeight(6000)/log2(6000)<<endl;       
  cout<<"n:7000"<<"\t\tHeight:"<<getTestHeight(7000)<<"\tHeight/Log2N:"<<getTestHeight(7000)/log2(7000)<<endl;       
  cout<<"n:8000"<<"\t\tHeight:"<<getTestHeight(8000)<<"\tHeight/Log2N:"<<getTestHeight(8000)/log2(8000)<<endl;       
  cout<<"n:9000"<<"\t\tHeight:"<<getTestHeight(9000)<<"\tHeight/Log2N:"<<getTestHeight(9000)/log2(9000)<<endl;       
  cout<<"n:10000"<<"\t\tHeight:"<<getTestHeight(10000)<<"\tHeight/Log2N:"<<getTestHeight(10000)/log2(10000)<<endl;   
  return 0;                                                                                                          
}                                                                                                                    
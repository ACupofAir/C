#include "MyQueue.h"
                             
int main(void)                     
{                                  
  MyQueue<char> que;               
  char items[11];                  
  cout<<"Put 10 nums to queue: \n";
  cin.get(items, 11);              
  for(int i = 0; i < 10; i++)      
  {                                
    que.push(items[i]);            
  }                                
  que.split_queue();               
  return 0;                        
}                                  
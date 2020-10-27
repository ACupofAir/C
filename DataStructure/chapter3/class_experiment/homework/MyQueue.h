#ifndef MYQUEUE_H
#define MYQUEUE_H       
                          
#include <queue>           
#include <iostream>        
using namespace std;        
                            
template<class T>           
class MyQueue: public queue<T> 
{                           
  public:                   
    void print_queue()                
    {                                 
      while(!this->empty())           
      {                               
        cout<<this->front();          
        this->pop();                  
      }                               
      cout<<endl;
    }                                 
    void split_queue()                
    {                                 
      MyQueue<T> temp_que1, temp_que2;
      while(!this->empty())           
      {                               
        temp_que1.push(this->front());
        this->pop();                  
        temp_que2.push(this->front());
        this->pop();                  
      }                               
      cout<<"sub1: \n";
      temp_que1.print_queue();
      cout<<"sub2: \n";
      temp_que2.print_queue();
    }                                 
};                                    
                                      
#endif                                
#ifndef MYSTACK_H
#define MYSTACK_H                  
#include <stack>                   
#include <iostream>                
using namespace std;               
                                          
template <class T>                        
class MyStack : public stack<T>           
{                                         
  public:                                 
    void print_stk()                      
    {                                     
      while (!this->empty())                    
      {                                         
        cout << this->top();                    
        this->pop();                            
      }                                         
      cout<<endl;                               
    }                                           
                                                
    void split_stk()                            
    {                                              
      MyStack<T> temp_stk1,temp_stk2;              
      while(!this->empty())                        
      {                                            
        temp_stk1.push(this->top());               
        this->pop();                               
        temp_stk2.push(this->top());               
        this->pop();                               
      }                                            
      cout<<"sub1:"<<endl;                         
      temp_stk1.print_stk();                       
      cout<<"sub2:"<<endl;                         
      temp_stk2.print_stk();                       
    }                               
                                    
    void add_stk(MyStack<T> temp_stk)
    {                               
      while(!temp_stk.empty())      
      {                             
        this->push(temp_stk.top());
        temp_stk.pop();             
      }                             
    }                               
};                                                 
                                                   
#endif                                             
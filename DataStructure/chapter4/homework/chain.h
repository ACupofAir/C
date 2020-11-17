#ifndef CHAIN_H
#define CHAIN_H                         
#include <iostream>                     
using namespace std;                    
                                        
template <class T>                        
class node                                
{                                         
  public:                                
    T data;                               
    node *next;                           
    node(T data)                          
    {                                     
      this->data = data;                  
    }                                     
};                                        
                                          
template <class T>                        
class chain                               
{                                               
  public:                                       
    node<T> *head;                              
    node<T> *tail;                              
    int position;                                
  public:                                        
    chain()                                      
    {                                            
      head = tail = NULL;                        
    }                                            
                                                 
    void add(T data);                            
    void delete_one_node(node<T>* p);            
    void traverse();                             
};                                               
                                                 
    template <class T>                           
    void chain<T>::add(T data)                         
    {                                            
      if (head == NULL)                          
      {                                          
        head = tail = new node<T>(data);         
        head->next = NULL;                       
        tail->next = NULL;                       
      }                                          
      else                                       
      {                                          
        node<T>* p  = new node<T>(data);         
        tail->next = p;                          
        tail = p;                                
        tail->next = NULL;                       
      }                                          
    }                                            
                                                 
    template <class T>                           
    void chain<T>::traverse() {                  
      node<T>* p = this->head;                   
      while(p) {                                 
        cout<<p->data<<"\t";                     
        p = p->next;                             
      }                                          
      cout<<"The chain is ended\n";              
    }                                            
                                                 
    template <class T>                           
    void chain<T>::delete_one_node(node<T>* p) { 
      if(p == this->head) {                      
        head = head->next;                       
      } else {                                   
        p->data = p->next->data;                 
        p->next = p->next->next;                 
      }                                          
    }                                            
                                                 
#endif                                           
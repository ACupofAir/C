#ifndef DELETENODE_H
#define DELETENODE_H                                  
#include <list>                                       
#include <iterator>                                   
using namespace std;                                  
                                                      
template <typename T>                                 
void print_a_node(list<T> myList, list<T>::iterator x) {
  list<T>::iterator temp_it = x;                   
  cout<<*temp_it;                                  
}                                                  
// void deleteNode(list<T> myList, list<T>::iterator x) {
//   list<T>::iterator it_begin = myList.begin();        
//   list<T>::iterator it_end = myList.end();            
//   if (x == myList.begin())                            
//   {                                                   
//     myList.begin() = ++it_begin;                      
//   }                                                   
//   else if (x == myList.end())                         
//   {                                                   
//     myList.end() = --it_end;                          
//   }                                                   
//   else                                                
//   {                                                   
//     *x = *next(x);                                    
//     x = next(x);                                      
//   }                                                   
// }                                                     
                                                         
                                                         
#endif                                                   
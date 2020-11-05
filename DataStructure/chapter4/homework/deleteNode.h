#ifndef DELETENODE_H
#define DELETENODE_H                            
#include <list>                                 
using namespace std;                            
                                                
template <typename T>                           
void deleteNode(list<T> myList, List<T>::iterator x) {
  List<T>::iterator it_begin = myList.begin();   
  List<T>::iterator it_end = myList.end();       
  if(x==myList.begin()) {                          
    myList.begin() = ++it_begin;                 
  } else if(x==myList.end()) {                   
    myList.end() = --it_end;                     
  } else {                                       
    temp = x+2;            
    *x = *(x+1);           
    x+1 = x+2;             
  }                                              
}                                                
                                                 
                                                 
#endif                                           
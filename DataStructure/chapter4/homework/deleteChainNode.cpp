#include <iostream>
#include "chain.h"          
using namespace std;        
                            
int main(void) {            
  chain<int> myList;        
  myList.add(1);            
  myList.add(2);            
  myList.add(3);            
  myList.add(4);            
  myList.traverse();        
  node<int>*p = myList.head;
  p = myList.head->next->next;     
  myList.delete_one_node(p);
  myList.traverse();        
  return 0;                 
}                           